/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <nt2/sdk/config/utils.hpp>

namespace nt2{ namespace config { namespace utils{

bool has_bit_set(int value, int bit)
{
  return (value & (1<<bit)) != 0;
}

int get_byte(int reg, int pos)
{
  const int dec = pos * 8;
  return ((reg & (0x000000FF << dec)) >> dec); 
}

int  get_range(int reg, int begin, int end)
{
  int mask=0x00000000;
  assert( begin < end );
  for(int i = 0; i < (end - begin); i++) { mask <<= 1; mask |= 0x1; }
  return ((reg >> begin) & mask);
}

///////////////////
//Common functions
///////////////////
int gcd(int a, int b )
{
  if(b == 0) return a; else return gcd(b, a%b);
}

int lcm(int a, int b )
{
  if(b ==0) return 0;
  return (a*b)/gcd(a,b);
}

} } }
