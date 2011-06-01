/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_IMPL_INVTRIG_F_INVTRIG_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_IMPL_INVTRIG_F_INVTRIG_HPP_INCLUDED
#include <nt2/include/functions/bitofsign.hpp>
#include <nt2/include/functions/bitwise_notand.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/any.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/sdk/simd/tags.hpp>
#include <nt2/include/constants/digits.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0 >
      struct invtrig_base<A0,radian_tag,trig_tag,tag::simd_type, float>
      {
	
	static inline A0 asin(const A0& a0)
	{
	  A0 sign, x;
	  //	bf::tie(sign, x) = sign_and_abs(a0);
	  x = nt2::abs(a0);
	  sign = bitofsign(a0);
	  A0 x_smaller_1e_4 = lt(x, single_constant<A0, 0x38d1b717>()); //1.0e-4f;
	  A0 x_larger_05    = gt(x, Half<A0>());
	  A0 x_else         = b_or(x_smaller_1e_4, x_larger_05);
	  A0 a = b_and(x, x_smaller_1e_4);
	  A0 b = b_and(Half<A0>()*oneminus(x), x_larger_05);
	  A0 z = b_or(b_or(b_notand(x_else, sqr(x)), a), b);
	  x = b_notand(x_else, x);
	  a = b_and(sqrt(z), x_larger_05);
	  x = b_or(a, x);
	  A0 z1 = madd(z,  single_constant<A0, 0x3d2cb352>(), single_constant<A0, 0x3cc617e3>());
	  z1 = madd(z1, z, single_constant<A0, 0x3d3a3ec7>());
	  z1 = madd(z1, z, single_constant<A0, 0x3d9980f6>());
	  z1 = madd(z1, z, single_constant<A0, 0x3e2aaae4>());
	  z1 = madd(z1, z*x, x);
	  z = select(x_smaller_1e_4, z, z1);
	  z1 = z+z;
	  z1 = Pio_2<A0>()-z1;
	  z = select(x_larger_05, z1, z);
	  return b_xor(z, sign);
	}
	
	static inline A0 acos(const A0& a0)
	{
	  A0 x = nt2::abs(a0);
	  A0 z2 = asin(a0);
	  A0 isgtxh = gt(x, Half<A0>());
	  if (nt2::any(isgtxh))
	    {
	      A0 z1 = asin(sqrt(oneminus(x)*Half<A0>()))*Two<A0>();
	      z2 = select(isgtxh, z1, z2);
	    }
	  z2 = select(lt(a0, -Half<A0>()), Pi<A0>()-z2, z2);
	  return select(isgtxh, z2, Pio_2<A0>()-z2);
	  //	return Pi_o_2<A0>()-asin(a0); 
	}
	
	static inline A0 atan(const A0& a0)
	{
	  A0 x, sign;
	  x = nt2::abs(a0);
	  sign = bitofsign(a0);
	  //	bf::tie(sign, x) = sign_and_abs(a0);
	  const A0 flag1 = lt(x, single_constant<A0, 0x401a827a>()); //tan3pio8);
	  const A0 flag2 = b_and(ge(x, single_constant<A0, 0x3ed413cd>()), flag1);
	  A0 yy =  b_notand(flag1, Pio_2<A0>());
	  yy =  select(flag2, Pio_4<A0>(), yy);
	  A0 xx =   select(flag1, x, -rec(x));
	  xx =  select(flag2, (minusone(x)/oneplus(x)),xx);
	  const A0 z = sqr(xx);
	  A0 z1 = madd(z,  single_constant<A0, 0x3da4f0d1>(),single_constant<A0, 0xbe0e1b85>());
	  A0 z2 = madd(z,  single_constant<A0, 0x3e4c925f>(),single_constant<A0, 0xbeaaaa2a>());
	  z1 = madd(z1, sqr(z), z2);
	  yy =  add(yy, madd(xx, mul( z1, z), xx));
	  return b_xor(yy, sign);
	}
      }; 
    }
  }
}

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of f_invtrig.hpp
// /////////////////////////////////////////////////////////////////////////////
