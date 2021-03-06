/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::constants true/false"

#include <nt2/include/constants/true_false.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test value of true/false constants for every base real types
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL  (  true_false_value, (double)(float) )
{
  NT2_TEST_EQUAL( nt2::False<T>()       , static_cast<T>(0) );
  NT2_TEST_EQUAL( nt2::True<T>()        , static_cast<T>(1) );
}
