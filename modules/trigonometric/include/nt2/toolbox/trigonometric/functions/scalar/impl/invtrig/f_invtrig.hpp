/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SCALAR_IMPL_INVTRIG_F_INVTRIG_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTIONS_SCALAR_IMPL_INVTRIG_F_INVTRIG_HPP_INCLUDED
#include <nt2/include/functions/bitofsign.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/bitwise_notand.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/sign.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_inf.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/multiplies.hpp>
#include <nt2/include/functions/plus.hpp>
#include <nt2/sdk/simd/tags.hpp>
#include <nt2/include/constants/real.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0,
		 class unit_tag,
		 class style,
		 class base_A0 = typename meta::scalar_of<A0>::type
		 > 
       struct invtrig_base{};

      template < class A0 > 
      struct invtrig_base<A0,radian_tag,tag::not_simd_type, float>
      {
	static inline A0 asin(const  A0& a0)
	{
	  A0 sign, x, z;
	  //	bf::tie(sign, x) = sign_and_abs(a0);
	  x = nt2::abs(a0);
	  sign = bitofsign(a0);
	  if ((x < single_constant<A0,0x38d1b717>())) return a0;
	  if ((x >  One<A0>())) return Nan<A0>();
	  bool bx_larger_05    = (x > Half<A0>());
	  if (bx_larger_05)
	    {
	      z = Half<A0>()*oneminus(x);
	      x =  sqrt(z);
	    }
	  else
	    {
	      z = sqr(x);
	    }
	  A0 z1 = madd(z,  single_constant<A0,0x3d2cb352>(),
		       single_constant<A0,0x3cc617e3>());
	  z1 = madd(z1, z, single_constant<A0,0x3d3a3ec7>());
	  z1 = madd(z1, z, single_constant<A0,0x3d9980f6>());
	  z1 = madd(z1, z, single_constant<A0,0x3e2aaae4>());
	  z1 = madd(z1, z*x, x);
	  if(bx_larger_05)
	    {
	      z1 = z1+z1;
	      z1 = Pio_2<A0>()-z1;
	    }
	  return b_xor(z1, sign);
	}

	static inline A0 acos(const  A0& a0)
	{
	  if (a0 < -Half<float>())
	    return Pi<float>()-asin( nt2::sqrt(oneplus(a0)*Half<float>()))*Two<float>();
	  else if (a0 > Half < float>())
	    return asin( nt2::sqrt(oneminus(a0)*Half<float>()))*Two<float>();
	  return (Pio_2<float>()-asin(a0));
	}

	static inline A0 atan(const  A0& a0)
	{
  	  if (is_eqz(a0))  return a0;
  	  if (is_inf(a0)) return Pio_2<A0>()*sign(a0);
          A0 y;
	  A0 x = nt2::abs(a0);
	  A0 sgn =  bitofsign(a0);
	  if( x >single_constant<float,0x401a827a>())//2.414213562373095 )  /* tan 3pi/8 */
	    {
	      y = Pio_2<A0>();
	      x = -rec(x);
	    }

	  else if( x > single_constant<float,0x3ed413cd>()) //0.4142135623730950f ) /* tan pi/8 */
	    {
	      y = Pio_4<A0>();
	      x = minusone(x)/oneplus(x);
	    }
	  else
	    y = 0.0;

	  A0 z = sqr(x);
 	  A0 z1 = madd(z,  single_constant<A0,0x3da4f0d1>(),single_constant<A0,0xbe0e1b85>());
 	  A0 z2 = madd(z,  single_constant<A0,0x3e4c925f>(),single_constant<A0,0xbeaaaa2a>());
 	  z1 = madd(z1, sqr(z), z2);
 	  y =  add(y, madd(x, mul( z1, z), x));
// 	  y +=
// 	    ((( 8.05374449538e-2 * z
// 		- 1.38776856032E-1) * z
// 	      + 1.99777106478E-1) * z
// 	     - 3.33329491539E-1) * z * x
// 	    + x;

	  return b_xor(sgn, y );

	}
      }; 
    }
  }
}



#endif

// /////////////////////////////////////////////////////////////////////////////
// End of f_invtrig.hpp
// /////////////////////////////////////////////////////////////////////////////
