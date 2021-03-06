/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_PACK_META_PRIMITIVE_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_PACK_META_PRIMITIVE_OF_HPP_INCLUDED

#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/simd/sdk/simd/pack/forward.hpp>

namespace boost { namespace dispatch { namespace meta
{
  template< class Type
          , std::size_t Cardinal
          >
  struct primitive_of< boost::simd::pack<Type, Cardinal> >
  {
    typedef Type type;
  };
} } }

#endif

