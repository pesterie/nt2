//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTIONS_SIMD_SSE_SSE2_HMSB_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTIONS_SIMD_SSE_SSE2_HMSB_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

#include <boost/simd/toolbox/reduction/functions/hmsb.hpp>
#include <boost/simd/include/functions/popcnt.hpp>

namespace boost { namespace simd { namespace ext
{
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is type8
  /////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::hmsb_, boost::simd::tag::sse2_,
                       (A0),
                       ((simd_<type8_<A0>,boost::simd::tag::sse_>))
                      )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      return _mm_movemask_epi8(a0);
    }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is type32
  /////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::hmsb_, boost::simd::tag::sse2_,
                       (A0),
                       ((simd_<type32_<A0>,boost::simd::tag::sse_>))
                      )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef typename dispatch::meta::as_real<A0>::type type;
      return _mm_movemask_ps(native_cast<type>(a0));
    }
  };

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is type64
  /////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::hmsb_, boost::simd::tag::sse2_,
                       (A0),
                       ((simd_<type64_<A0>,boost::simd::tag::sse_>))
                      )
  {
    typedef int32_t result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef typename dispatch::meta::as_real<A0>::type type;
      return _mm_movemask_pd(native_cast<type>(a0));
    }
  };
} } }
#endif
#endif
