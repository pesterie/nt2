//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - genmask/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of bitwise components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by $author$ the $date$
/// modified by $author$ the $date$
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/bitwise/include/genmask.hpp>

NT2_TEST_CASE_TPL ( genmask_real__1,  NT2_REAL_TYPES)
{
  using nt2::genmask;
  using nt2::tag::genmask_;
  typedef typename nt2::meta::call<genmask_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  genmask(nt2::Inf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  genmask(nt2::Minf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  genmask(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  genmask(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for real_

NT2_TEST_CASE_TPL ( genmask_integer__1,  NT2_INTEGRAL_TYPES)
{
  using nt2::genmask;
  using nt2::tag::genmask_;
  typedef typename nt2::meta::call<genmask_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  genmask(nt2::One<T>()), nt2::Mone<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  genmask(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_SCALAR_BUFFER(a0,T, NR, T(-10000), T(10000));
    double ulp0 = 0.0, ulpd = 0.0;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::genmask(a0),a0?nt2::Mone<r_t>():nt2::Zero<r_t>(),0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for integer_