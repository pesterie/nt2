//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SQRT2_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SQRT2_HPP_INCLUDED

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/register.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_SIMD_CONSTANT_REGISTER( Sqrt_2, double, 1
                                , 0x3FB504F3, 0x3ff6A09E667F3BCCULL
                                );
  }
  
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Sqrt_2, Sqrt_2)
} }

#endif
