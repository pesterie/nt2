/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::constants eps related"

#include <nt2/sdk/meta/supported_types.hpp>
#include <nt2/sdk/constant/eps_related.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test value of eps constants for every base real types
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE( double_eps_value )
{
  NT2_TEST_EQUAL( nt2::Eps<double>()            , 2.220446049250313e-16   );
  NT2_TEST_EQUAL( nt2::Halfeps<double>()        , 1.1102230246251565e-16  );
  NT2_TEST_EQUAL( nt2::Threeeps<double>()       , 6.661338147750939e-16   );
  NT2_TEST_EQUAL( nt2::Sqrteps<double>()        , 1.4901161193847656e-8   );
  NT2_TEST_EQUAL( nt2::Fourthrooteps<double>()  , 1.2207031250000000e-4   );
  NT2_TEST_EQUAL( nt2::Thirdrooteps<double>()   , 6.0554544523933440e-6   );
  NT2_TEST_EQUAL( nt2::Mlogeps2<double>()       , 18.021826694558580      );
  NT2_TEST_EQUAL( nt2::Mindenormal<double>()    , 5.0000000000000000e-324 );
  NT2_TEST_EQUAL( nt2::Smallestposval<double>() , 2.2250738585072014e-308 );
}

NT2_TEST_CASE( float_eps_value )
{
  NT2_TEST_EQUAL( nt2::Eps<float>()             , 1.1920928955078125e-7  );
  NT2_TEST_EQUAL( nt2::Halfeps<float>()         , 5.960464477539063e-8   );
  NT2_TEST_EQUAL( nt2::Threeeps<float>()        , 3.5762786865234375e-7  );
  NT2_TEST_EQUAL( nt2::Sqrteps<float>()         , 0.0003452669770922512  );
  NT2_TEST_EQUAL( nt2::Fourthrooteps<float>()    , 0.018581360578536987   );
  NT2_TEST_EQUAL( nt2::Thirdrooteps<float>()    , 0.004921566694974899   );
  NT2_TEST_EQUAL( nt2::Mlogeps2<float>()        , 7.971192359924316      );
  NT2_TEST_EQUAL( nt2::Mindenormal<float>()     , 1.401298464324817e-45  );
  NT2_TEST_EQUAL( nt2::Smallestposval<float>()  , 1.1754943508222875e-38 );
}

////////////////////////////////////////////////////////////////////////////////
// Test value of eps constants for every base integral types
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL( real_value, NT2_INTEGRAL_TYPES )
{
  NT2_TEST_EQUAL( nt2::Eps<T>()             , 1 );
  NT2_TEST_EQUAL( nt2::Halfeps<T>()         , 1 );
  NT2_TEST_EQUAL( nt2::Threeeps<T>()        , 1 );
  NT2_TEST_EQUAL( nt2::Sqrteps<T>()         , 3 );
  NT2_TEST_EQUAL( nt2::Fourthrooteps<T>()    , 1 );
  NT2_TEST_EQUAL( nt2::Thirdrooteps<T>()    , 1 );
  NT2_TEST_EQUAL( nt2::Mlogeps2<T>()        , 0 );
  NT2_TEST_EQUAL( nt2::Mindenormal<T>()     , 1 );
  NT2_TEST_EQUAL( nt2::Smallestposval<T>()  , 1 );
}
