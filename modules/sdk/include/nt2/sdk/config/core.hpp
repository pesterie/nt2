/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef _CORE_HPP_INCLUDED_
#define _CORE_HPP_INCLUDED_

#include <nt2/sdk/config/configurator/cpuid.hpp>
#include <nt2/sdk/config/configurator/utils.hpp>

namespace nt2{ namespace config {

bool is_multithreaded(void);
int  get_threads(void);
int  get_physical_cores(void);
int  get_logical_cores(void);

} }

#endif /* _CORE_HPP_INCLUDED_ */
