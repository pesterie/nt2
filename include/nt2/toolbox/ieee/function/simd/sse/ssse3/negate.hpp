//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_SSE_SSSE3_NEGATE_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_SSE_SSSE3_NEGATE_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for negate

  template<class Extension,class Info>
  struct call<negate_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0)>
    : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      typename nt2::meta::scalar_of<A0>::type,
      (5, (real_,int32_t,int16_t,int8_t,unsigned_))
     )

    NT2_FUNCTOR_CALL_EVAL_IF(2,    real_)
    {
      A0 tmp = isnez(a1)&a0;
      tmp = select(isltz(a1), -a0, tmp);
      tmp = seladd(isnan(a1), tmp, a1); //TODO signed Nan ?
      return tmp;
    }

    NT2_FUNCTOR_CALL_EVAL_IF(2,  int32_t)
    {
      A0 tmp = { _mm_sign_epi32( a0, a1)};
      return tmp;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,  int16_t)
    {
      A0 tmp = { _mm_sign_epi16( a0, a1)};
      return tmp;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,   int8_t)
    {
      A0 tmp = { _mm_sign_epi8 ( a0, a1)};
      return tmp;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, unsigned)
    {
      return  b_and(a0, isnez(a1));
    }
    };
} }

#endif