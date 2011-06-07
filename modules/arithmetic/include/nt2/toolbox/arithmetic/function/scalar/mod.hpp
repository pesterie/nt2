//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_MOD_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_MOD_HPP_INCLUDED

#include <nt2/include/functions/idivfloor.hpp>
/////////////////////////////////////////////////////////////////////////////
// The mod function computes the remainder of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to -inf.
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::mod_, tag::cpu_,
                     (A0)(A1),
                     (fundamental_<A0>)(fundamental_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::mod_(tag::fundamental_,tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a1 ? a0-a1*idivfloor(a0,a1) : a0;
    }

  };
} }

#endif
// modified by jt the 26/12/2010
