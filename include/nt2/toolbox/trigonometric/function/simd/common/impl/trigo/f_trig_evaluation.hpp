/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_IMPL_TRIGO_F_TRIG_EVALUATION_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_IMPL_TRIGO_F_TRIG_EVALUATION_HPP_INCLUDED

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template <class A0> struct trig_evaluation < A0, trig_tag, tag::simd_type, float>
      {

	typedef typename meta::as_integer<A0, signed>::type int_type;
	typedef typename meta::scalar_of<A0>::type stype; 
	static inline A0 cos_eval(const A0 z, const A0, const A0)
	{
	  const A0 y = horner< NT2_HORNER_COEFF_T(stype, 3, (0x37ccf5ce, 0xbab60619, 0x3d2aaaa5) ) > (z);
	  return oneplus(madd(z,Mhalf<A0>(), y*sqr(z)));
	}
	static inline A0 sin_eval(const A0 z, const A0 x, const A0)
	{
	  const A0 y1 = horner< NT2_HORNER_COEFF_T(stype, 3, (0xb94ca1f9, 0x3c08839d, 0xbe2aaaa2) ) > (z);
	  return madd(mul(y1,z),x,x);
	}
	static inline A0 base_tancot_eval(const A0 z)
	{
	  const A0 zz = sqr(z);
	  return horner< NT2_HORNER_COEFF_T(stype, 6, (0x3c19c53b, 
						     0x3b4c779c, 
						     0x3cc821b5, 
						     0x3d5ac5c9, 
						     0x3e0896dd, 
						     0x3eaaaa6f))>(zz)*zz*z+z;
	}
	static inline A0 tan_eval(const A0 z, const A0,  const int_type n)
	{
	  A0 y = base_tancot_eval(z); 
	  return sel(is_equal(n, One<int_type>()),y,-rec(y)); 
	}
	static inline A0 cot_eval(const A0 z, const A0,  const int_type n)
	{
	  A0 y = base_tancot_eval(z); 
	  return sel(is_equal(n, One<int_type>()),rec(y),-y); 
	}
      };
    }
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of f_trig_evaluation.hpp
// /////////////////////////////////////////////////////////////////////////////
