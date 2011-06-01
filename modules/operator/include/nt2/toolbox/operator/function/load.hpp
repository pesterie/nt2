//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_LOAD_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_LOAD_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/operator/include.hpp>

////////////////////////////////////////////////////////////////////////////////
// Load from memory functor and function
// Documentation: http://nt2.lri.fr/sdk/memory/function/load.html
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/meta/as.hpp>
#include <nt2/sdk/functor/preprocessor/function.hpp>

namespace nt2
{
  namespace tag { struct load_ {}; }

  //////////////////////////////////////////////////////////////////////////////
  // Load a data of type T from the memory zone given by (a0,a1)
  //////////////////////////////////////////////////////////////////////////////
  template<class T,class A0,class A1> inline
  typename meta::enable_call<tag::load_ ( A0 const&, A1 const&
                                        , meta::as_<T>
                                        )
                            >::type
  load(A0 const& a0,A1 const& a1 )
  {
    typename make_functor<tag::load_, A0>::type callee;
    return callee(a0,a1,meta::as_<T>());
  }

  //////////////////////////////////////////////////////////////////////////////
  // Load a data of type T from the memory zone given by (a0,a1) and a sub-type
  // level offset
  //////////////////////////////////////////////////////////////////////////////
  template<class T,int Offset, class A0,class A1> inline
  typename meta::enable_call<tag::load_ ( A0 const&, A1 const&
                                        , meta::as_<T>
                                        , boost::mpl::int_<Offset>
                                        )
                            >::type
  load(A0 const& a0,A1 const& a1 )
  {
    typename make_functor<tag::load_, A0>::type callee;
    return callee(a0,a1,meta::as_<T>(),boost::mpl::int_<Offset>());
  }
}

#include <nt2/toolbox/operator/function/scalar/load.hpp>
#include <nt2/toolbox/operator/function/simd/all/load.hpp>

#endif
