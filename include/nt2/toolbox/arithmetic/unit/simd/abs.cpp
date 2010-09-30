//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - abs - simd/unit Mode"

#include <nt2/toolbox/arithmetic/include/abs.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <../unit/sdk/simd/types.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic component abs using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(abs, NT2_SIMD_TYPES )
{
 using nt2::abs;
 using nt2::functors::abs_;
 using nt2::load; 
 using nt2::simd::native;
 using nt2::meta::cardinal_of;

 typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
 typedef native<T,ext_t>             n_t;
 typedef typename nt2::meta::call<abs_(n_t)>::type call_type;

 NT2_TEST( (boost::is_same<call_type, n_t>::value) );
 NT2_ALIGNED_TYPE(T) data[1*cardinal_of<n_t>::value];
 for(std::size_t i=0;i<1*cardinal_of<n_t>::value;++i)
   data[i] = i-cardinal_of<n_t>::value/2; // good value here for abs

   n_t a0 = load<n_t>(&data[0],0);
   n_t v  = abs(a0);
   for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
   {
     NT2_TEST_EQUAL( v[j], abs(a0[j]) );
   }
 }

