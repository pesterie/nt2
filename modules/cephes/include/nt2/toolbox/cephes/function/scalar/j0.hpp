//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_J0_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_J0_HPP_INCLUDED

  extern "C"{
    extern float cephes_j0f ( float );
    extern double cephes_j0 ( double );
    extern long double cephes_j0l ( long double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::j0_, tag::cpu_,
                    (A0),
                    (arithmetic_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::j0_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::cephes::j0(type(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::j0_, tag::cpu_,
                    (A0),
                    (double_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::j0_(tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_j0(a0); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::j0_, tag::cpu_,
                    (A0),
                    (float_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::j0_(tag::float_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_j0f(a0); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is long double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::j0_, tag::cpu_,
                    (A0),
                    (long_double_<A0>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::j0_(tag::long_double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_j0l(a0); }
  };
} }

#endif
// modified by jt the 29/12/2010