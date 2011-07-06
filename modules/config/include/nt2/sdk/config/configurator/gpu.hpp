//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_SDK_CONFIG_CONFIGURATOR_GPU_HPP
#define NT2_SDK_CONFIG_CONFIGURATOR_GPU_HPP

#include <nt2/sdk/config/infos.hpp>

#ifdef NT2_HAS_CUDA_SUPPORT
#include <cuda_runtime_api.h>
#elif defined(NT2_HAS_OPENCL_SUPPORT)
#include <cl.h>
#endif

#include <vector>
#include <iostream>

namespace nt2 { namespace config {

#ifdef NT2_HAS_CUDA_SUPPORT
    
    typedef cudaDeviceProp         gpu_infos;
    typedef std::vector<gpu_infos> gpu_report;

#elif defined(NT2_HAS_OPENCL_SUPPORT)

#endif

    // template<class T>
    // inline int get_gpu_attribute(T* attribute, CUdevice_attribute da, int device)
    // {
    //   if(CUDA_SUCCESS == cuDeviceGetAttribute(attribute, da, device)) return 0;
    //   else return -1;
    // }

    int get_gpu_devices_properties(gpu_report &gpu);
    //void display_gpu_device_properties(gpu_infos const& device);    

} }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_GPU_HPP */
