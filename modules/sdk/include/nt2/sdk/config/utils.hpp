/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef _UTILS_HPP_INCLUDED_
#define _UTILS_HPP_INCLUDED_

#include <cassert>
#include <iostream>

namespace nt2 { namespace config { namespace utils {

bool has_bit_set(int value, int bit);
int  get_byte(int reg, int pos);
int  get_range(int reg, int begin, int end);
int  gcd(int a, int b );
int lcm(int a, int b );

} } }

#endif /* _UTILS_HPP_INCLUDED_ */


