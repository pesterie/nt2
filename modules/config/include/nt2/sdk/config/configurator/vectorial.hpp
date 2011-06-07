/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 *******************************************************************************/
#ifndef _VECTORIAL_HPP_INCLUDED_
#define _VECTORIAL_HPP_INCLUDED_

#include <string>
#include <nt2/sdk/config/configurator/cpuid.hpp>
#include <nt2/sdk/config/configurator/utils.hpp>

namespace nt2{ namespace config {

int has_vectorial_extension(std::string target);

struct matcher
{
  int function,reg,bit;
};

} }

#endif /* _VECTORIAL_HPP_INCLUDED_ */
