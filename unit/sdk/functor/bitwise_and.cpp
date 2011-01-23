/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::bitwise_and"

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/functor/operators.hpp>
#include <nt2/sdk/meta/supported_types.hpp>
#include <boost/type_traits/is_same.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test behavior for bitwise_and
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( bitwise_and, NT2_INTEGRAL_TYPES )
{
  using boost::is_same;
  using nt2::tag::bitwise_and_;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<bitwise_and_(T,T)>::type
                            , T
                            >::value
            )
          );

  NT2_TEST_EQUAL( nt2::b_and(1,2)       , 1 & 2 );
  NT2_TEST_EQUAL( nt2::bitwise_and(1,2) , 1 & 2 );
}

////////////////////////////////////////////////////////////////////////////////
// Test behavior for bitwise_and on real
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( bitwise_and_real, NT2_REAL )
{
  using boost::is_same;
  using nt2::tag::bitwise_and_;
  typedef typename nt2::meta::as_integer<T>::type int_t;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<bitwise_and_(T,int_t)>::type
                            , T
                            >::value
            )
          );

  int_t mask = (1LL << (sizeof(T)*CHAR_BIT)-1);

  NT2_TEST_EQUAL( nt2::bitwise_and(T(-1.) ,mask ), T(-0.) );
  NT2_TEST_EQUAL( nt2::b_and(T(-1.) ,mask ), T(-0.) );
}
