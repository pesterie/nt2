//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_SIN_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_SCALAR_SIN_HPP_INCLUDED

  extern "C"{
    extern double sin_rn ( double );
    extern double sin_rd ( double );
    extern double sin_rz ( double );
    extern double sin_ru ( double );
  };


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(crlibm::tag::sin_<Rounding>, tag::cpu_,
                     (A0)(Rounding),
                     (arithmetic_<A0>)
                    )

namespace nt2 { namespace ext
{
  template<class Rounding,class Dummy>
  struct call<crlibm::tag::sin_<Rounding>(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};
    NT2_FUNCTOR_CALL(1)
    {
      return nt2::crlibm::sin<Rounding>(double(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(crlibm::tag::sin_<Rounding>, tag::cpu_,
                     (A0)(Rounding),
                     (double_<A0>)
                    )

namespace nt2 { namespace ext
{
  template<class Rounding,class Dummy>
  struct call<crlibm::tag::sin_<Rounding>(tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      meta::result_of<meta::floating(A0)>{};

    template<class A0, class R> struct inner_sin;
    NT2_CRLIBM_INNER_STRUCT(rn, sin, rn)
    NT2_CRLIBM_INNER_STRUCT(rd, sin, rd)
    NT2_CRLIBM_INNER_STRUCT(ru, sin, ru)
    NT2_CRLIBM_INNER_STRUCT(rz, sin, rd)


    NT2_FUNCTOR_CALL(1)
      {return inner_sin<A0,Rounding>::eval(a0, Rounding()); }
  };
} }

#endif
// modified by jt the 29/12/2010