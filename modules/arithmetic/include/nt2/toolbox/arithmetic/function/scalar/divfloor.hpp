//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_DIVFLOOR_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_DIVFLOOR_HPP_INCLUDED
#include <nt2/include/functions/divceil.hpp>
#include <nt2/include/functions/rdivide.hpp>
#include <nt2/include/functions/floor.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is signed_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divfloor_, tag::cpu_,
                           (A0)(A1),
                           (signed_<A0>)(signed_<A1>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divfloor_(tag::signed_,tag::signed_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
       return -divceil(-a0,a1);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divfloor_, tag::cpu_,
                           (A0)(A1),
                           (arithmetic_<A0>)(arithmetic_<A1>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divfloor_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      return (!a1) ? a1 : rdivide(a0,a1);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divfloor_, tag::cpu_,
                           (A0)(A1),
                           (real_<A0>)(real_<A1>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divfloor_(tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::floor(a0/a1);
    }
  };
} }

#endif
