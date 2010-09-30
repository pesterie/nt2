//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - #fctname/scalar Mode"

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/toolbox/arithmetic/include/iceil.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////


NT2_TEST_CASE_TPL ( iceil,  (double)(nt2::uint64_t)(nt2::int64_t) 
                          (float)(nt2::uint32_t)(nt2::int32_t)  
                          (nt2::uint16_t)(nt2::int16_t)         
                          (nt2::uint8_t)(nt2::int8_t)
                  )
{
  using nt2::iceil;
  using nt2::functors::iceil_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<iceil_(T)>::type
              , typename nt2::meta::as_integer<T>::type
              >::value)
           );
<<<<<<< Updated upstream:include/nt2/toolbox/arithmetic/unit/scalar/iceil.cpp
  NT2_TEST_EQUAL(  iceil( T(42) ), 42 );
  NT2_TEST_EQUAL(  iceil( T(-42) ), -42 );
}
NT2_TEST_CASE_TPL ( real_iceil,  (double)(float)
                  )
{
  using nt2::iceil;
  using nt2::functors::iceil_;

 NT2_TEST( (boost::is_same < typename nt2::meta::call<iceil_(T)>::type
             ,typename nt2::meta::as_integer<T>::type
             >::value)
          );
 NT2_TEST_EQUAL(  iceil( T(42.1) ), 43 );
 NT2_TEST_EQUAL(  iceil( T(-42.1) ), -42 );
}        
=======
//   NT2_TEST_EQUAL(  iceil( T(42) ), 42 );
//   NT2_TEST_EQUAL(  iceil( T(-42) ), -42 );
}
          
>>>>>>> Stashed changes:include/nt2/toolbox/arithmetic/unit/scalar/iceil.cpp