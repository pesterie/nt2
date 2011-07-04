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

#include <cuda_runtime_api.h>
#include <vector>

namespace nt2 { namespace config {
    
    typedef struct gpu_infos_
    {
      int max_threads_per_block;
      //Add more properties
    } gpu_infos;

    typedef std::vector<gpu_infos> gpu_report;

    int get_cuda_devices_properties(gpu_report &gpu);
    
} }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_GPU_HPP */
