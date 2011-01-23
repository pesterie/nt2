//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 ieee toolbox - bitfloating/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// modified by jt the 04/12/2010
/// modified by jt the 12/12/2010
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/ieee/include/bitfloating.hpp>
// specific includes for arity 1 tests
#include <nt2/include/functions/bitinteger.hpp>

NT2_TEST_CASE_TPL ( bitfloating_uint32_t_1,  (nt2::uint32_t))
{
  using nt2::bitfloating;
  using nt2::tag::bitfloating_;
  typedef typename nt2::meta::call<bitfloating_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_real<T>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, 0, 100);
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::bitinteger(nt2::bitfloating(a0)),a0,0);
     }
   }
} // end of test for uint32_t

NT2_TEST_CASE_TPL ( bitfloating_uint64_t_1,  (nt2::uint64_t))
{
  using nt2::bitfloating;
  using nt2::tag::bitfloating_;
  typedef typename nt2::meta::call<bitfloating_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_real<T>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, 0, 100);
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::bitinteger(nt2::bitfloating(a0)),a0,0);
     }
   }
} // end of test for uint64_t

NT2_TEST_CASE_TPL ( bitfloating_int32_t_1,  (nt2::int32_t))
{
  using nt2::bitfloating;
  using nt2::tag::bitfloating_;
  typedef typename nt2::meta::call<bitfloating_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_real<T>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, -100, 100);
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::bitinteger(nt2::bitfloating(a0)),a0,0);
     }
   }
} // end of test for int32_t

NT2_TEST_CASE_TPL ( bitfloating_int64_t_1,  (nt2::int64_t))
{
  using nt2::bitfloating;
  using nt2::tag::bitfloating_;
  typedef typename nt2::meta::call<bitfloating_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_real<T>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 

  // random verifications
  static const uint32_t NR = 100;
  {
    NT2_CREATE_BUFFER(a0,T, 100, -100, 100);
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::bitinteger(nt2::bitfloating(a0)),a0,0);
     }
   }
} // end of test for int64_t