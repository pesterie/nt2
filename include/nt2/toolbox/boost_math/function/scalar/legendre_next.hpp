//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTION_SCALAR_LEGENDRE_NEXT_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTION_SCALAR_LEGENDRE_NEXT_HPP_INCLUDED


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::legendre_next_, tag::cpu_,
                               (A0)(A1)(A2)(A3),
                               (arithmetic_<A0>)(arithmetic_<A1>)(arithmetic_<A2>)(arithmetic_<A3>)
                              )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::legendre_next_(tag::arithmetic_,tag::arithmetic_,tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2, class A3>
    struct result<This(A0, A1, A2, A3)> :
      boost::result_of<meta::floating(A0, A1, A2, A3)>{};

    NT2_FUNCTOR_CALL(4)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::boost_math::legendre_next(a0, a1, type(a2), type(a3));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::legendre_next_, tag::cpu_,
                               (A0)(A1)(A2)(A3),
                               (real_<A0>)(real_<A1>)(real_<A2>)(real_<A3>)
                              )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::legendre_next_(tag::real_,tag::real_,tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2, class A3>
    struct result<This(A0, A1, A2, A3)> :
      boost::result_of<meta::floating(A0, A1, A2, A3)>{};

    NT2_FUNCTOR_CALL(4){ return boost::math::legendre_next(a0, a1, a2, a3); }
  };
} }

#endif
// modified by jt the 26/12/2010