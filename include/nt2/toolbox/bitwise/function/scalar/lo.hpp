//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_LO_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_LO_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>


namespace nt2 { namespace functors
{

  //  no special validate for lo

  /////////////////////////////////////////////////////////////////////////////
  // Compute lo(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<lo_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      meta::as_integer<A0,unsigned>{};

    NT2_FUNCTOR_CALL(1)
    {
       typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      BOOST_STATIC_CONSTANT(type, shift = sizeof(type)*4);
      BOOST_STATIC_CONSTANT(type, pattern = (type(type(-1)<<shift)>>shift));

      return b_and(pattern, a0);
    }
  };
} }


      
#endif