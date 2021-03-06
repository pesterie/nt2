/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_CONFIG_COMPILER_GCC_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_COMPILER_GCC_HPP_INCLUDED

#if !defined(BOOST_SIMD_COMPILER)
  #if defined(__GNUC__)

    #define BOOST_SIMD_COMPILER_GNU_C
    #define BOOST_SIMD_COMPILER BOOST_COMPILER
    

  #endif
#endif
#endif
