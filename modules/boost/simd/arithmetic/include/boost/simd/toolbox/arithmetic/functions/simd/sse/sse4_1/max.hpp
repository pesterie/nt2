//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_SSE4_1_MAX_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_SSE4_1_MAX_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE4_1_SUPPORT

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::sse_>))
                              ((simd_<double_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  {_mm_max_pd(a0,a1)}; return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<float_<A0>,boost::simd::tag::sse_>))
                              ((simd_<float_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  {_mm_max_ps(a0,a1)}; return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<uint8_<A0>,boost::simd::tag::sse_>))
                              ((simd_<uint8_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
         A0 that =  {_mm_max_epu8(a0,a1)}; return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<int8_<A0>,boost::simd::tag::sse_>))
                              ((simd_<int8_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
         A0 that =  {_mm_max_epi8(a0,a1)}; return that;
    }
  };


  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<uint16_<A0>,boost::simd::tag::sse_>))
                              ((simd_<uint16_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  { _mm_max_epu16(a0,a1)}; return that;
    }
  };
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                              ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  { _mm_max_epi16(a0,a1)}; return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<uint32_<A0>,boost::simd::tag::sse_>))
                              ((simd_<uint32_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  { _mm_max_epu32(a0,a1)}; return that;
    }
  };
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::max_, boost::simd::tag::sse4_1_, (A0)
                            , ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                              ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that =  { _mm_max_epi32(a0,a1)}; return that;
    }
  };

} } }

#endif
#endif
