//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTION_SCALAR_IBETAC_INVB_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTION_SCALAR_IBETAC_INVB_HPP_INCLUDED


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(boost_math::tag::ibetac_invb_, tag::cpu_,
                             (A0)(A1)(A2),
                             (arithmetic_<A0>)(arithmetic_<A1>)(arithmetic_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<boost_math::tag::ibetac_invb_(tag::arithmetic_,tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> :
      meta::result_of<meta::floating(A0, A1, A2)>{};

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::boost_math::ibetac_invb(type(a0), type(a1), type(a2));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(boost_math::tag::ibetac_invb_, tag::cpu_,
                             (A0)(A1)(A2),
                             (real_<A0>)(real_<A1>)(real_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<boost_math::tag::ibetac_invb_(tag::real_,tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1, class A2>
    struct result<This(A0, A1, A2)> :
      meta::result_of<meta::floating(A0, A1, A2)>{};

    NT2_FUNCTOR_CALL(3){ return boost::math::ibetac_invb(a0, a1, a2); }
  };
} }

#endif
// modified by jt the 29/12/2010