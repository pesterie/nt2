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

    int get_gpu_devices_properties(gpu_report &gpu)
    {

#ifdef NT2_HAS_CUDA_SUPPORT

      int nb_devices = 0;
      cudaGetDeviceCount( &nb_devices );
      gpu.resize(nb_devices);
      std::cout << "Getting GPU devices specifications...\n";
      for(size_t device_idx =0; device_idx < nb_devices; ++device_idx)
      {
	memset( &gpu[device_idx], 0, sizeof(cudaDeviceProp));
	if(cudaSuccess == cudaGetDeviceProperties(&gpu[device_idx], device_idx))
	{
	  std::cout << "-- GPU device ID : " << device_idx << " -> Success\n";
	}
	else 
	{
	  std::cerr << "-- GPU device ID : " << device_idx << " -> Fail\n";
	}
      }

#elif defined(NT2_HAS_OPENCL_SUPPORT)

#endif

    }

}  }
