//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 hyperbolic toolbox - atanh/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// $testcat$ test behavior of hyperbolic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 20/02/2011
/// modified by jt the 05/06/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/hyperbolic/include/atanh.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/exponential/include/constants.hpp>
extern "C" { long double cephes_atanhl(long double); }
#include <nt2/toolbox/boost_math/include/atanh.hpp>

NT2_TEST_CASE_TPL ( atanh_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::atanh;
  using nt2::tag::atanh_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<atanh_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-1), T(1));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::atanh(a0),::cephes_atanhl(a0),1.5);
        ulp0=nt2::max(ulpd,ulp0);
        NT2_TEST_ULP_EQUAL( nt2::atanh(a0),nt2::boost_math::atanh(a0),1.0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( atanh_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::atanh;
  using nt2::tag::atanh_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<atanh_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( atanh_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::atanh;
  using nt2::tag::atanh_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<atanh_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for signed_int_
