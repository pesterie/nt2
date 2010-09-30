//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_AVX_MIN_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_AVX_MIN_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>

#include <nt2/include/functions/seladd.hpp>
#include <nt2/include/functions/details/simd/sse/sse4_1/min.hpp>

namespace nt2 { namespace functors
{
  //  no special validate for min

  template<class Extension,class Info>
  struct call<min_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      typename nt2::meta::scalar_of<A0>::type,
      (9, (float,double,int8_t,int16_t,int32_t,uint8_t,uint16_t,uint32_t,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,       float)
    {
      A0 that =  {_mm256_min_ps(a0,a1)}; return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,      double)
    {
      A0 that =  {_mm256_min_pd(a0,a1)}; return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int8_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epi8); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int16_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epi16); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int32_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epi32); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     uint8_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epu8); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     uint16_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epu16); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     uint32_t)
    {
      NT2_AVX_JOIN128INT(that, _mm_min_epu32); return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, arithmetic_)
    {
       return seladd( is_lt(a0,a1),a0,a1-a0);
    }
  };
} }

#endif