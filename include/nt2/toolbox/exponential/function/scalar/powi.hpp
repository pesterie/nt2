//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_POWI_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_POWI_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/include/functions/abs.hpp>

namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<powi_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : 
      boost::is_integral<A1>{};
  }; 
  /////////////////////////////////////////////////////////////////////////////
  // Compute powi(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<powi_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : 
      boost::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type type;
      const type one = One<type>();
      type x = nt2::abs(a0);
      A1 sign_n = signnz(a1);
      A1 n = abs(a1);
      
      type n_oddf = isodd(n);
      type nf = n_oddf;
      
      type y = madd(n_oddf,x,one-n_oddf);
      type w = x;
      n >>=1;
      
      while( n )
	{
	  w =sqr( w);
	  n_oddf = isodd(n);
	  y = y*madd(n_oddf,w,one-n_oddf);
	  n >>=1;
	}
      
      w = copysign(y, a0);
      y = madd(nf, w, (one-nf)*y);
      
      w = rec(y);
      x = shri(oneplus(sign_n),1);  // 1 if positive, else 0
      return madd(x,y,(one-x)*w);
    }
  };
} }


      
#endif