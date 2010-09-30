//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BESSEL_FUNCTION_SIMD_COMMON_Y1_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTION_SIMD_COMMON_Y1_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/j1.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/select.hpp>


namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<y1_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      meta::is_real_convertible<A0>{};
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute y1(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<y1_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :  meta::as_real<A0>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (3, (float,double,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,  float)
    {
      typedef typename meta::scalar_of<A0>::type sA0;       
      A0 z = sqr(a0); 
      A0 p2 = (z-integral_constant<A0, 0x40954ae7> ())*a0*
	horner< NT2_HORNER_COEFF_T(sA0, 5,
				 (0x320a80f5, 
				  0xb57eeb2e, 
				  0x388ceb47, 
				  0xbb2d21cf, 
				  0x3d2c210b
				  ) ) > (z);
      A0 q = rec(a0);
      p2 = p2+integral_constant<A0, 0x3f22f983>()*(j1(a0)*log(a0)-q);
      A0 a0lt2 = islt(a0, Two<A0>()); 
      if (all(a0lt2)) return p2; 
      
      A0 w = sqrt(q); 
      
      A0 p3 = w *
	horner< NT2_HORNER_COEFF_T(sA0, 8,
				 (0x3d8d98f9, 
				  0xbe69f6b3, 
				  0x3ea0ad85, 
				  0xbe574699, 
				  0x3bb21b25, 
				  0x3e18ec50, 
				  0x36a6f7c5, 
				  0x3f4c4229
				  ) ) > (q);
      w = sqr(q);
      A0 xn =  q*
	horner< NT2_HORNER_COEFF_T(sA0, 8,
				 (0xc233e16d,
				  0x424af04a, 
				  0xc1c6dca7, 
				  0x40e72299, 
				  0xbfc5bd69, 
				  0x3eb364d9, 
				  0xbe27bad7, 
				  0x3ebfffdd
				  ) ) > (w)-integral_constant<A0,0x4016cbe4 > ();
      p3 = p3*sin(xn+a0); 
      return select (a0lt2, p2, p3); 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, double)
    {
	A0 r; 
	map(functor<y1_>(), a0, r);
	return r; 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,       arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return nt2::y1(tofloat(a0));
    }
  };
} }

      
#endif