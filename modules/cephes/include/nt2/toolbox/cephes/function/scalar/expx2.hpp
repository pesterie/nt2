//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_EXPX2_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_EXPX2_HPP_INCLUDED

  extern "C"{
    extern float cephes_expx2f ( float);
    extern double cephes_expx2 ( double, int );
    extern long double cephes_expx2l ( long double, int );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::expx2_, tag::cpu_,
                       (A0),
                       (arithmetic_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::expx2_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::cephes::expx2(type(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::expx2_, tag::cpu_,
                       (A0),
                       (double_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::expx2_(tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_expx2(a0, 1); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::expx2_, tag::cpu_,
                       (A0),
                       (float_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::expx2_(tag::float_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_expx2f(a0); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is long double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(cephes::tag::expx2_, tag::cpu_,
                       (A0),
                       (long_double_<A0>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<cephes::tag::expx2_(tag::long_double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1){ return cephes_expx2ll(a0, 1); }
  };
} }

#endif
// modified by jt the 29/12/2010