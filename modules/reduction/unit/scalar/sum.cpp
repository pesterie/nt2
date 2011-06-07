//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 reduction toolbox - sum/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of reduction components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 24/02/2011
/// modified by jt the 19/03/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/reduction/include/sum.hpp>
// specific includes for arity 1 tests
#include <nt2/sdk/meta/logical.hpp>

NT2_TEST_CASE_TPL ( sum_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::sum;
  using nt2::tag::sum_;
  typedef typename nt2::meta::scalar_of<T>::type sT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<sum_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::result_of<nt2::meta::arithmetic(sT,sT)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(sum(nt2::Inf<T>()), nt2::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(nt2::Minf<T>()), nt2::Minf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(nt2::Mone<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(nt2::Nan<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(nt2::One<T>()), nt2::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename nt2::meta::scalar_of<T>::type sT;
    NT2_CREATE_BUF(tab_a0,T, NR, nt2::Valmin<T>(), nt2::Valmax<T>());
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::sum(a0),a0,0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_
