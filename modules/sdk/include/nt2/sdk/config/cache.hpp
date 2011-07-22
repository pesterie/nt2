/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef _CACHE_HPP_INCLUDED_
#define _CACHE_HPP_INCLUDED_

#include <nt2/sdk/config/configurator/cpuid.hpp>
#include <nt2/sdk/config/configurator/utils.hpp>
#include <iostream>

namespace nt2{ namespace config {

typedef struct 
{
  int L1,L2,L3;
  int l1,l2,l3;
} cache_report;

int  get_cache_infos(cache_report &cache);
int  get_cache_sizes_intel(cache_report &cache);
int  get_cache_sizes_amd(cache_report &cache);
int  get_cache_coherency_line_size(int &size);
int  get_cache_coherency_line_size(cache_report const& cache);

}  }

#endif /* _CACHE_HPP_INCLUDED_ */
