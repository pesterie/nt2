//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_J0_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_J0_HPP_INCLUDED
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/digits.hpp>

#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/cos.hpp>
#include <nt2/include/functions/is_inf.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::j0_, tag::cpu_,
                    (A0),
                    (arithmetic_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::j0_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::j0(type(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::j0_, tag::cpu_,
                    (A0),
                    (double_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::j0_(tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1) {
      if (is_inf(a0)) return Zero<A0>();
      return ::j0(a0);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::j0_, tag::cpu_,
                    (A0),
                    (float_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::j0_(tag::float_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<A0>::type stype;
      if (is_inf(a0)) return Zero<A0>();
      A0 x = nt2::abs(a0);
      if (x < 1.0e-3f) return oneminus(Quarter<A0>()*sqr(x));
      if (x <= Two<A0>())
        {
          A0 z = sqr(x);
          return (z-single_constant<float,0x40b90fdc> ())*
            horner< NT2_HORNER_COEFF_T(stype, 5,
                   (0xb382511c,
              0x36d660a0,
              0xb9d01fb1,
              0x3c5a6271,
              0xbe3110a6
              ) ) > (z);
        }
      A0 q = rec(x);
      const A0 p3 = nt2::sqrt(q) *
        horner< NT2_HORNER_COEFF_T(stype, 8,
               (0xbd8c100e,
                0x3e3ef887,
                0xbe5ba616,
                0x3df54214,
                0xbb69539e,
                0xbd4b8bc1,
                0xb6612dc2,
                0x3f4c422a
                ) ) > (q);
            const A0 xn =  q*
              horner< NT2_HORNER_COEFF_T(stype, 8,
               (0x4201aee0,
                0xc2113945,
                0x418c7f6a,
                0xc09f3306,
                0x3f8040aa,
                0xbe46a57f,
                0x3d84ed6e,
                0xbdffff97
                ) ) > (sqr(q))-Pio_4<A0>();
      return p3*nt2::cos(xn+x);
    }
  };
} }

#endif
// modified by jt the 26/12/2010