//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/gpu.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <cstring>
#include <cstdlib>

#define NT2_OPENCL_PLATFORM_ALLOWED 1
#define NT2_OPENCL_DEVICES_ALLOWED  4

namespace nt2 { namespace config {

    int get_gpu_devices_properties(gpu_report &gpu)
    {

#ifdef NT2_HAS_CUDA_SUPPORT

      int nb_devices = 0;
      if(cudaSuccess != cudaGetDeviceCount( &nb_devices ) ) 
      {
	std::cerr << "-- No CUDA devices found.\n";
	return -1;
      }
      std::vector<cudaDeviceProp> temp;
      temp.resize(nb_devices);
      gpu.resize(nb_devices);
      std::cout << "Getting GPU devices specifications using CUDA...\n";
      for(size_t device_idx =0; device_idx < nb_devices; ++device_idx)
      {
	memset( &temp[device_idx], 0, sizeof(cudaDeviceProp));
	if(cudaSuccess == cudaGetDeviceProperties(&temp[device_idx], device_idx))
	{
	  gpu[device_idx].name = std::string(temp[device_idx].name);
	  gpu[device_idx].total_global_mem = temp[device_idx].totalGlobalMem;
	  gpu[device_idx].shared_mem_per_block = temp[device_idx].sharedMemPerBlock;
	  gpu[device_idx].max_threads_per_block = temp[device_idx].maxThreadsPerBlock;
	  gpu[device_idx].max_threads_dim[0] = temp[device_idx].maxThreadsDim[0];
	  gpu[device_idx].max_threads_dim[1] = temp[device_idx].maxThreadsDim[1];
	  gpu[device_idx].max_threads_dim[2] = temp[device_idx].maxThreadsDim[2];
	  gpu[device_idx].clock_rate = temp[device_idx].clockRate;
	  gpu[device_idx].total_const_mem = temp[device_idx].totalConstMem;
	  gpu[device_idx].total_compute_units = temp[device_idx].multiProcessorCount;
	  gpu[device_idx].max_grid_size[0]  = temp[device_idx].maxGridSize[0];
	  gpu[device_idx].max_grid_size[1]  = temp[device_idx].maxGridSize[1];
	  gpu[device_idx].max_grid_size[2]  = temp[device_idx].maxGridSize[2];
	  gpu[device_idx].max_texture_2D[0] = temp[device_idx].maxTexture2D[0];
	  gpu[device_idx].max_texture_2D[1] = temp[device_idx].maxTexture2D[1];
	  gpu[device_idx].max_texture_3D[0] = temp[device_idx].maxTexture3D[0];
	  gpu[device_idx].max_texture_3D[1] = temp[device_idx].maxTexture3D[1];
	  gpu[device_idx].max_texture_3D[2] = temp[device_idx].maxTexture3D[2];
	  gpu[device_idx].max_texture_1D_layered[0] = temp[device_idx].maxTexture1DLayered[0];
	  gpu[device_idx].max_texture_1D_layered[1] = temp[device_idx].maxTexture1DLayered[1];
	  gpu[device_idx].max_texture_2D_layered[0] = temp[device_idx].maxTexture2DLayered[0];
	  gpu[device_idx].max_texture_2D_layered[1] = temp[device_idx].maxTexture2DLayered[1];
	  gpu[device_idx].max_texture_2D_layered[2] = temp[device_idx].maxTexture2DLayered[2];
	  gpu[device_idx].texture_alignment = temp[device_idx].textureAlignment;
	  gpu[device_idx].max_texture_1D = temp[device_idx].maxTexture1D;
	  gpu[device_idx].L2_cache_size = temp[device_idx].l2CacheSize;
	  gpu[device_idx].max_threads_per_compute_units = temp[device_idx].maxThreadsPerMultiProcessor;
	  std::cout << "-- GPU device ID : " << device_idx << " -> Success\n";
	  display_gpu_device_properties(gpu[device_idx]);
	}
	else 
	{
	  std::cerr << "-- GPU device ID : " << device_idx << " -> Fail\n";
	}
      }

#elif defined(NT2_HAS_OPENCL_SUPPORT)
	
	std::cout << "Getting GPU devices specifications using OpenCL...\n";
	const cl_uint num_entries_platform = NT2_OPENCL_PLATFORM_ALLOWED;
	cl_uint num_platforms;
	cl_platform_id* platforms = (cl_platform_id*)malloc(NT2_OPENCL_PLATFORM_ALLOWED*sizeof(cl_platform_id));
	
	const cl_uint num_entries_device = NT2_OPENCL_DEVICES_ALLOWED;
	cl_uint num_devices;
	cl_device_id* devices = (cl_device_id*)malloc(NT2_OPENCL_DEVICES_ALLOWED*sizeof(cl_device_id));
	char     name[256];
	cl_ulong total_global_mem;
	cl_ulong shared_mem_per_block;
	size_t   max_threads_per_block;
	cl_uint  max_dimensions;
	size_t*  max_threads_dim;
	cl_uint  clock_rate;
	cl_ulong total_const_mem;
	cl_uint  total_compute_units;
	size_t*  param_value_size_ret;
	size_t   current_size = 0;

	if(CL_SUCCESS == clGetPlatformIDs(num_entries_platform, platforms, &num_platforms))
	{
	  for(size_t platform_idx = 0; platform_idx < NT2_OPENCL_PLATFORM_ALLOWED; ++platform_idx)
	  {
	    if(CL_SUCCESS == clGetDeviceIDs(platforms[platform_idx], CL_DEVICE_TYPE_GPU, num_entries_device, devices, &num_devices))
	    {
	      for(size_t device_idx = 0; device_idx < num_devices; ++device_idx)
	      {
		current_size = gpu.size();
		gpu.resize(current_size + 1);

		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_NAME, sizeof(char[256]), (void*)&name[0], param_value_size_ret))
		{
		  gpu[current_size].name = std::string(name);
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), (void*)&total_global_mem, param_value_size_ret))
		{
		  gpu[current_size].total_global_mem = total_global_mem;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(cl_ulong), (void*)&shared_mem_per_block, param_value_size_ret))
		{
		  gpu[current_size].shared_mem_per_block = shared_mem_per_block;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), (void*)&max_threads_per_block, param_value_size_ret))
		{
		  gpu[current_size].max_threads_per_block = max_threads_per_block;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), (void*)&max_dimensions, param_value_size_ret))
		{
		  max_threads_dim = new size_t[max_dimensions];
		  if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_WORK_ITEM_SIZES, max_dimensions*sizeof(size_t), (void*)&max_threads_dim[0], param_value_size_ret))
		  {
		    gpu[current_size].max_threads_dim[0] = max_threads_dim[0];
		    gpu[current_size].max_threads_dim[1] = max_threads_dim[1];
		    gpu[current_size].max_threads_dim[2] = max_threads_dim[2];
		  }
		  delete[] max_threads_dim;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_uint), (void*)&clock_rate, param_value_size_ret))
		{
		  gpu[current_size].clock_rate = clock_rate;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE, sizeof(cl_ulong), (void*)&total_const_mem, param_value_size_ret))
		{
		  gpu[current_size].total_const_mem = total_const_mem;
		}
		if(CL_SUCCESS == clGetDeviceInfo(devices[device_idx], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_ulong), (void*)&total_compute_units, param_value_size_ret))
		{
		  gpu[current_size].total_compute_units = total_compute_units;
		}
		
		std::cout << "-- GPU device ID : " << device_idx << " -> Success\n";
		display_gpu_device_properties(gpu[current_size]);
	      }
	      std::cout << "-- GPU device ID : " << device_idx << " -> Fail\n";      
	    }
	  }
	  
	}
	else
	{
	  
	  free(devices);
	  free(platforms);
	  return -1;
	}

	free(devices);
	free(platforms);


#endif

	return 0;
    }

    void display_gpu_device_properties(gpu_infos const& device)
    {
      std::cout << "---- Name:......................." << device.name << "\n";
      std::cout << "---- Total Global Memory:........" << device.total_global_mem << "\n";
      std::cout << "---- Shared Memory Per Block:...." << device.shared_mem_per_block << "\n";
      std::cout << "---- Max Threads Per Block:......" << device.max_threads_per_block << "\n";
      std::cout << "---- Max Threads Dimension 0:...." << device.max_threads_dim[0] << "\n";
      std::cout << "---- Max Threads Dimension 1:...." << device.max_threads_dim[1] << "\n";
      std::cout << "---- Max Threads Dimension 2:...." << device.max_threads_dim[2] << "\n";
      std::cout << "---- Clock Rate:................." << device.clock_rate << "\n";
      std::cout << "---- Total Constant Memory:......" << device.total_const_mem << "\n";
      std::cout << "---- Total Compute Units:........" << device.total_compute_units << "\n";
      std::cout << "---- Max Grid Size Dimension 0:.." << device.max_grid_size[0]  << "\n";
      std::cout << "---- Max Grid Size Dimension 1:.." << device.max_grid_size[1] << "\n";
      std::cout << "---- Max Grid Size Dimension 2:.." << device.max_grid_size[2] << "\n";
      std::cout << "---- Max Texture 2D Dim. 0:......" << device.max_texture_2D[0] << "\n";
      std::cout << "---- Max Texture 2D Dim. 1:......" << device.max_texture_2D[1] << "\n";
      std::cout << "---- Max Texture 3D Dim. 0:......" << device.max_texture_3D[0] << "\n";
      std::cout << "---- Max Texture 3D Dim. 1:......" << device.max_texture_3D[1] << "\n";
      std::cout << "---- Max Texture 3D Dim. 2:......" << device.max_texture_3D[2] << "\n";
      std::cout << "---- Max Texture 1DLay Dim. 0:..." << device.max_texture_1D_layered[0] << "\n";
      std::cout << "---- Max Texture 1DLay Dim. 1:..." << device.max_texture_1D_layered[1] << "\n";
      std::cout << "---- Max Texture 2DLay Dim. 0:..." << device.max_texture_2D_layered[0] << "\n";
      std::cout << "---- Max Texture 2DLay Dim. 1:..." << device.max_texture_2D_layered[1] << "\n";
      std::cout << "---- Max Texture 2DLay Dim. 2:..." << device.max_texture_2D_layered[2] << "\n";
      std::cout << "---- Texture Alignment:.........." << device.texture_alignment << "\n";
      std::cout << "---- Max Texture 1D:............." << device.max_texture_1D << "\n";
      std::cout << "---- L2 Cache Size:.............." << device.L2_cache_size << "\n";
      std::cout << "---- Max Threads/Compute Units:.." << device.max_threads_per_compute_units  << "\n";
    }

}  }
