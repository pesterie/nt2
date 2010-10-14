/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::constants infinites"

#include <limits>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/constant/properties.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test value of infinites for every base real types
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL( real_inf, (double)(float) )
{
  NT2_TEST_EQUAL( nt2::Inf<T>() , std::numeric_limits<T>::infinity()  );
  NT2_TEST_EQUAL( nt2::Minf<T>(), -std::numeric_limits<T>::infinity() );
}

////////////////////////////////////////////////////////////////////////////////
// Test value of infinites for every base integral types
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( int_inf
                  , (nt2::int64_t)(nt2::int32_t)(nt2::int16_t)(nt2::int8_t)
                    (nt2::uint64_t)(nt2::uint32_t)(nt2::uint16_t)(nt2::uint8_t)
                  )
{
  NT2_TEST_EQUAL( nt2::Inf<T>() , nt2::Valmax<T>()  );
  NT2_TEST_EQUAL( nt2::Minf<T>(), nt2::Valmin<T>()  );
}