/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 *******************************************************************************/
#ifndef NT2_SDK_CONFIG_VECTORIAL_HPP_INCLUDED
#define NT2_SDK_CONFIG_VECTORIAL_HPP_INCLUDED

#include <string>
#include <nt2/sdk/config/cpuid.hpp>
#include <nt2/sdk/config/utils.hpp>

namespace nt2{ namespace config {

int has_vectorial_extension(std::string const& target);

struct matcher
{
  int function,reg,bit;
};

} }

#endif /* NT2_SDK_CONFIG_VECTORIAL_HPP_INCLUDED */
