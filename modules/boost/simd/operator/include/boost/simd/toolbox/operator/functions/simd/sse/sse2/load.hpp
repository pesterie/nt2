//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_SSE2_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_SSE2_LOAD_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

////////////////////////////////////////////////////////////////////////////////
// load for SSE2 SIMD types
////////////////////////////////////////////////////////////////////////////////
#include <boost/dispatch/meta/mpl.hpp>
#include <boost/simd/sdk/simd/category.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/dispatch/details/ignore_unused.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

//==============================================================================
// load vector of double
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< double_<A2>, X > >))
                            )
  {
    typedef typename A2::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_pd(a0+a1*boost::simd::meta::cardinal_of<result_type>::value) };
      return that;
    }
  };
} } }

//==============================================================================
// load vector of float
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< float_<A2>, X > >))
                            )
  {
    typedef typename A2::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_ps(a0+a1*boost::simd::meta::cardinal_of<result_type>::value) };
      return that;
    }
  };
} } }

//==============================================================================
// load vector of integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)(X)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< integer_<A2>,X > >))
                            )
  {
    typedef typename A2::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      ignore_unused(a2);
      result_type
      that = { _mm_load_si128(reinterpret_cast<__m128i const*>(a0)+a1) };
      return that;
    }
  };
} } }


#include <boost/simd/toolbox/operator/functions/simd/sse/sse2/load_offset.hpp>

#endif
#endif
