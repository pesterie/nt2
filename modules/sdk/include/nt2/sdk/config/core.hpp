/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_CORE_HPP_INCLUDED
#define NT2_SDK_CONFIG_CORE_HPP_INCLUDED

#include <nt2/sdk/config/cpuid.hpp>
#include <nt2/sdk/config/utils.hpp>

namespace nt2{ namespace config {

bool is_multithreaded(void);
int  nb_threads(void);
int  nb_physical_cores(void);
int  nb_logical_cores(void);

} }

#endif /* NT2_SDK_CONFIG_CORE_HPP_INCLUDED */
