//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - ffs/scalar Mode"

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
#include <nt2/toolbox/bitwise/include/ffs.hpp>

NT2_TEST_CASE_TPL ( ffs_float_1,  (float))
{
  using nt2::ffs;
  using nt2::tag::ffs_;
  typedef typename nt2::meta::call<ffs_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, unsigned>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Inf<T>()), 24, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Minf<T>()), 24, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Nan<T>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Signmask<T>()), sizeof(T)*8, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for float

NT2_TEST_CASE_TPL ( ffs_double_1,  (double))
{
  using nt2::ffs;
  using nt2::tag::ffs_;
  typedef typename nt2::meta::call<ffs_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, unsigned>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Inf<T>()), 53, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Minf<T>()), 53, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Nan<T>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Signmask<T>()), sizeof(T)*8, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for double

NT2_TEST_CASE_TPL ( ffs_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::ffs;
  using nt2::tag::ffs_;
  typedef typename nt2::meta::call<ffs_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, unsigned>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ffs(nt2::One<T>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Signmask<T>()), sizeof(T)*8, 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( ffs_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::ffs;
  using nt2::tag::ffs_;
  typedef typename nt2::meta::call<ffs_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::as_integer<T, unsigned>::type wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  ffs(nt2::One<T>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  ffs(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
//   uint64_t j = 1; 
//   for (int i =  0; i < 64; ++i)
//     {
//       j *= 2;
//       std::cout << j << "   " << ::ffsl(j) <<  std::endl; 
//       std::cout << j << "   " << nt2::ffs(j) <<  std::endl; 
//    }
} // end of test for unsigned_int_
