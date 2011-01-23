//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/arithmetic/include/ldiv.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>



//////////////////////////////////////////////////////////////////////////////
// Scalar Runtime benchmark for functor<ldiv_> from arithmetic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::ldiv_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) , T(V2))

NT2_TIMING(nt2::tag::ldiv_,(RS(float,1.0f,10000.0f))(RS(float,-10000.0f,10000.0f)))
NT2_TIMING(nt2::tag::ldiv_,(RS(double,1.0,10000.0))(RS(double,-10000.0,10000.0)))
NT2_TIMING(nt2::tag::ldiv_,(RS(int64_t,1,10000))(RS(int64_t,-10000,10000)))
NT2_TIMING(nt2::tag::ldiv_,(RS(int32_t,1,10000))(RS(int32_t,-10000,10000)))
NT2_TIMING(nt2::tag::ldiv_,(RS(int16_t,1,32767))(RS(int16_t,-32768,32767)))
NT2_TIMING(nt2::tag::ldiv_,(RS(int8_t,1,127))(RS(int8_t,-128,127)))
NT2_TIMING(nt2::tag::ldiv_,(RS(uint64_t,1,65535))(RS(uint64_t,1,65535)))
NT2_TIMING(nt2::tag::ldiv_,(RS(uint32_t,1,65535))(RS(uint32_t,1,65535)))
NT2_TIMING(nt2::tag::ldiv_,(RS(uint16_t,1,65535))(RS(uint16_t,1,65535)))
NT2_TIMING(nt2::tag::ldiv_,(RS(uint8_t,1,255))(RS(uint8_t,1,255)))

#undef RS