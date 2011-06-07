//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - fast_cotd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
/// modified by jt the 18/04/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/trigonometric/include/fast_cotd.hpp>

NT2_TEST_CASE_TPL ( fast_cotd_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::fast_cotd;
  using nt2::tag::fast_cotd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_cotd_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_cotd(-nt2::Zero<T>()), -nt2::Inf<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(-nt2::_180<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(-nt2::_45<T>()), nt2::Mone<r_t>(), 4.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(-nt2::_90<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Inf<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Minf<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Nan<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Zero<T>()), nt2::Inf<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::_180<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::_45<T>()), nt2::One<r_t>(), 4.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::_90<T>()), nt2::Nan<r_t>(), 1.0);
} // end of test for real_

NT2_TEST_CASE_TPL ( fast_cotd_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::fast_cotd;
  using nt2::tag::fast_cotd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_cotd_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Zero<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::_45<T>()), nt2::One<r_t>(), 4.0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( fast_cotd_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::fast_cotd;
  using nt2::tag::fast_cotd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<fast_cotd_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(fast_cotd(-nt2::_45<T>()), nt2::Mone<r_t>(), 4.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::Zero<T>()), nt2::Nan<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cotd(nt2::_45<T>()), nt2::One<r_t>(), 4.0);
} // end of test for signed_int_
