//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_RROR_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_RROR_HPP_INCLUDED

#include <nt2/include/functions/ror.hpp>
#include <nt2/include/functions/rol.hpp>

namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<rror_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      boost::is_integral<typename meta::strip<A1>::type >{}; 
  };
  /////////////////////////////////////////////////////////////////////////////
  // Compute rror(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<rror_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
      struct result<This(A0,A1)> : meta::strip <A0>{};


    NT2_FUNCTOR_CALL(2)
    {
      return (a1 > 0) ? ror(a0, a1) :rol(a0, -a1); 
    }
  };
} }


      
#endif