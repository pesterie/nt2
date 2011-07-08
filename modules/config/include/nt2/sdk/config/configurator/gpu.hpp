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
#include <CL/cl.h>
#endif

#include <cstring>
#include <vector>
#include <iostream>

namespace nt2 { namespace config {

    typedef struct
    {
      std::string name;
      size_t      max_threads_dim[3];
      size_t      max_grid_size[3];
      size_t      max_texture_2D[2];
      size_t      max_texture_3D[3];
      size_t      max_texture_1D_layered[2];
      size_t      max_texture_2D_layered[3];
      size_t      total_global_mem;
      size_t      shared_mem_per_block;
      size_t      max_threads_per_block;
      size_t      clock_rate;
      size_t      total_const_mem;
      size_t      total_compute_units;
      size_t      texture_alignment;
      size_t      max_texture_1D;
      size_t      L2_cache_size;
      size_t      max_threads_per_compute_units;
    } gpu_infos;
    
    typedef std::vector<gpu_infos> gpu_report;

    int  get_gpu_devices_properties(gpu_report &gpu);
    void display_gpu_device_properties(gpu_infos const& device);    

} }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_GPU_HPP */
