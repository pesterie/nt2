//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/bitwise/include/rol.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>



//////////////////////////////////////////////////////////////////////////////
// Scalar Runtime benchmark for functor<rol_> from bitwise
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::rol_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) , T(V2))

NT2_TIMING(nt2::tag::rol_,(RS(float,-10000.0f,10000.0f))(RS(int32_t,0,31)))
NT2_TIMING(nt2::tag::rol_,(RS(double,-10000.0,10000.0))(RS(int64_t,0,63)))
NT2_TIMING(nt2::tag::rol_,(RS(int64_t,-10000,10000))(RS(int64_t,0,63)))
NT2_TIMING(nt2::tag::rol_,(RS(int32_t,-10000,10000))(RS(int32_t,0,31)))
NT2_TIMING(nt2::tag::rol_,(RS(int16_t,-32768,32767))(RS(int16_t,0,16)))
NT2_TIMING(nt2::tag::rol_,(RS(int8_t,-128,127))(RS(int8_t,0,7)))
NT2_TIMING(nt2::tag::rol_,(RS(uint64_t,0,65535))(RS(uint64_t,0,63)))
NT2_TIMING(nt2::tag::rol_,(RS(uint32_t,0,65535))(RS(uint32_t,0,31)))
NT2_TIMING(nt2::tag::rol_,(RS(uint16_t,0,65535))(RS(uint16_t,0,16)))
NT2_TIMING(nt2::tag::rol_,(RS(uint8_t,0,255))(RS(uint8_t,0,7)))

#undef RS