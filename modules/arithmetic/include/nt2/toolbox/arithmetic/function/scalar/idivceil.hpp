//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_IDIVCEIL_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_IDIVCEIL_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/include/functions/sign.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/rdivide.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/iceil.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::idivceil_, tag::cpu_,
                          (A0)(A1),
                          (arithmetic_<A0>)(arithmetic_<A1>)
                         )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::idivceil_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type  type;
      return iceil(tofloat(a0)/tofloat(a1));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::idivceil_, tag::cpu_,
                          (A0)(A1),
                          (unsigned_<A0>)(unsigned_<A1>)
                         )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::idivceil_(tag::unsigned_,tag::unsigned_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type  type;
      return rdivide((a0+(a1-One<type>())), a1);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::idivceil_, tag::cpu_,
                          (A0)(A1),
                          (real_<A0>)(real_<A1>)
                         )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::idivceil_(tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::as_integer < typename meta::result_of<meta::arithmetic(A0,A1)>::type > {};

    NT2_FUNCTOR_CALL(2)
    {
      return iceil(a0/a1);
    }
  };
} }

#endif
// modified by jt the 26/12/2010
