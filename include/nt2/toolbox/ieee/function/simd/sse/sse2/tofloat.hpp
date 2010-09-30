//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SIMD_SSE_SSE2_TOFLOAT_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SIMD_SSE_SSE2_TOFLOAT_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/meta/templatize.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/meta/strip.hpp>

#include <nt2/include/functions/bitwise_andnot.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/maximum.hpp>
#include <nt2/include/functions/is_gez.hpp>

namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<tofloat_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::has_larger_or_equal_size < A0
				       , int32_t
				       , meta::scalar_of<boost::mpl::_>
                      > {};
  };
  template<class Extension,class Info>
  struct call<tofloat_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      { typedef typename meta::as_real<A0>::type  type; };

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (5, (int32_t,int64_t,uint32_t,uint64_t,real_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,     real_)
    {
      return a0; 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,     int32_t)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      type that = { _mm_cvtepi32_ps(a0)};
      return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,     int64_t)
    {
      typedef typename meta::as_real<A0>::type  type;
      typedef typename meta::scalar_of<type>::type sftype; 
      if (maximum(abs(a0)) > Valmax < int32_t > ())
	{
	  type const v = {{a0[0], a0[1]}};
	   return v;
	}
      typedef typename meta::int32_t_<A0>::type htype; 
      typedef simd::native<htype,tag::sse_> itype;
      itype tmp = {_mm_shuffle_epi32(a0, _MM_SHUFFLE(3, 1, 2, 0))};
      type v = { _mm_cvtepi32_pd(tmp)};
      return v;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,    uint32_t)
    {
      typedef typename meta::as_real<A0>::type  result_type;
      typedef typename meta::scalar_of<A0>::type stype;
      typedef typename meta::as_integer<A0,signed>::type sint_type;
      //      static const sint_type hibitmask = integral_constant<sint_type, 1ll << (8*sizeof(stype)-1) >() ;
      const result_type offset = integral_constant<result_type, 1ll << (8*sizeof(stype)-1) >() ;
      const sint_type a00 = simd::native_cast<sint_type>(a0);
      result_type v1 = {_mm_cvtepi32_ps(a00)};
      result_type v2 = {_mm_cvtepi32_ps((b_andnot(a00, Signmask<sint_type>())))};
      v2 = v2+offset;
      return sel(is_gez(a00),v1,v2);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,    uint64_t)
    {
      typedef typename meta::as_real<A0>::type  result_type;
      result_type const v = {{a0[0], a0[1]}};
      return v;

    }
  };
} }

#endif