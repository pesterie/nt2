//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/polynomials/include/hermite.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
typedef nt2::simd::native<float,ext_t> vfloat;
typedef nt2::simd::native<double,ext_t> vdouble;

//////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<hermite_> from polynomials
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::hermite_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, V1 , V2)

NT2_TIMING(nt2::tag::hermite_,(RS(int32_t,0,10))(RS(vdouble,-100.0,100.0))) 
NT2_TIMING(nt2::tag::hermite_,(RS(int32_t,0,10))(RS(vfloat,-100.0f,100.f)))

