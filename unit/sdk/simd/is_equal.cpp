/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::is_equal on SIMD types"

#include <nt2/sdk/simd/io.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test behavior for is_equal
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( is_equal, NT2_SIMD_TYPES )
{
  using boost::is_same;
  using nt2::tag::is_equal_;
  using nt2::simd::native;
  using nt2::meta::cardinal_of;

  typedef NT2_SIMD_DEFAULT_EXTENSION      ext_t;
  typedef native<T,ext_t>                 n_t;

  NT2_TEST( (boost::is_same < typename nt2::meta::call<is_equal_(n_t,n_t)>::type
                            , n_t
                            >::value
            )
          );

  NT2_ALIGNED_TYPE(T) data[2*cardinal_of<n_t>::value];
  for(std::size_t i=0;i<2*cardinal_of<n_t>::value;++i)
    data[i] = 1+i;

  n_t v = nt2::load<n_t>(&data[0],0);
  n_t w = nt2::load<n_t>(&data[0],1);
  for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
  {
    NT2_TEST( (nt2::is_equal(v,v))[j] );
    NT2_TEST( (nt2::eq(v,v))[j]       );
  }
  for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
  {
    NT2_TEST( !(nt2::is_equal(v,w))[j] );
    NT2_TEST( !(nt2::eq(v,w))[j]       );
  }
}
