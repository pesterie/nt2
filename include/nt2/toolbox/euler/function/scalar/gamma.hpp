//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_FUNCTION_SCALAR_GAMMA_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_SCALAR_GAMMA_HPP_INCLUDED
#include <boost/math/special_functions.hpp>
#include <boost/math/tr1.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/constant/real.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for gamma

  /////////////////////////////////////////////////////////////////////////////
  // Compute gamma(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<gamma_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      if (a0 == -Inf<A0>()) return Nan<A0>(); 
      return boost::math::tr1::tgamma(type(a0));  
    }

  };
} }


      
#endif