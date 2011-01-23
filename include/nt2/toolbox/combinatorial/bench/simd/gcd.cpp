//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/combinatorial/include/gcd.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <cmath> 
 
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
typedef nt2::simd::native<int64_t,ext_t> vint64_t;
typedef nt2::simd::native<int32_t,ext_t> vint32_t;
typedef nt2::simd::native<int16_t,ext_t> vint16_t;
typedef nt2::simd::native<int8_t,ext_t> vint8_t;
typedef nt2::simd::native<uint64_t,ext_t> vuint64_t;
typedef nt2::simd::native<uint32_t,ext_t> vuint32_t;
typedef nt2::simd::native<uint16_t,ext_t> vuint16_t;
typedef nt2::simd::native<uint8_t,ext_t> vuint8_t;

//////////////////////////////////////////////////////////////////////////////
// Simd Runtime benchmark for functor<gcd_> from combinatorial
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::gcd_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, V1 , V2)

NT2_TIMING(nt2::tag::gcd_,(RS(vint64_t,1,255))(RS(vint64_t,1,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vint32_t,1,255))(RS(vint32_t,1,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vint16_t,1,255))(RS(vint16_t,1,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vint8_t,1,127))(RS(vint8_t,1,127)))
NT2_TIMING(nt2::tag::gcd_,(RS(vuint64_t,0,255))(RS(vuint64_t,0,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vuint32_t,0,255))(RS(vuint32_t,0,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vuint16_t,0,255))(RS(vuint16_t,0,255)))
NT2_TIMING(nt2::tag::gcd_,(RS(vuint8_t,0,255))(RS(vuint8_t,0,255)))

#undef RS
