//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_SSE_SSE2_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_SSE_SSE2_BITWISE_ANDNOT_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF ( boost::simd::tag::bitwise_andnot_, boost::simd::tag::sse2_, (A0)(A1)
                                , (boost::mpl::equal_to < boost::mpl::sizeof_<A0>
                                                        , boost::mpl::sizeof_<A1>
                                                        >
                                  )
                                , ( boost::simd::tag::bitwise_andnot_
                                    ( simd_<arithmetic_<A0>,boost::simd::tag::sse_>
                                    , simd_<arithmetic_<A1>,boost::simd::tag::sse_>
                                    )
                                  )
                                , ((simd_<arithmetic_<A0>,boost::simd::tag::sse_>))
                                  ((simd_<arithmetic_<A1>,boost::simd::tag::sse_>))
                              )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename dispatch::meta::as_integer< A0 >::type int_type;
      A0     that = { simd::native_cast<A0>
                      ( _mm_andnot_si128( simd::native_cast<int_type>(a1)
                                        , simd::native_cast<int_type>(a0)
                                        )
                      )
                    };
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::bitwise_andnot_, boost::simd::tag::sse2_, (A0),
                             ((simd_<double_<A0>,boost::simd::tag::sse_>))
                             ((simd_<double_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm_andnot_pd(a1, a0)};
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_andnot_, boost::simd::tag::sse2_, (A0)
                            , ((simd_<float_<A0>,boost::simd::tag::sse_>))
                              ((simd_<float_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = {_mm_andnot_ps(a1, a0)};
      return that;
    }
  };
} } }

#endif
#endif
