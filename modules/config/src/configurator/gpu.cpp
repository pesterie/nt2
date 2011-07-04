//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/configurator/gpu.hpp>
#include <iostream>
#include <cstring>

namespace nt2 { namespace config {

    int get_cuda_devices_properties(gpu_report &gpu)
    {
      int nb_devices = 0;
      cudaGetDeviceCount( &nb_devices );
      cudaDeviceProp device_properties;
      gpu.resize(nb_devices);
      for(size_t device_idx =0; device_idx < nb_devices; ++device_idx)
      {
	memset( &device_properties, 0, sizeof(cudaDeviceProp));
	if(cudaSuccess == cudaGetDeviceProperties(&device_properties, device_idx))
	{
	  gpu[device_idx].max_threads_per_block = device_properties.maxThreadsPerBlock; 
	  //Add more properties
	}
      }
    }
    
}  }
