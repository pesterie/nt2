//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_KN_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_KN_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
        
  extern "C"{
    extern float cephes_knf ( int,float );
    extern double cephes_kn ( int,double );
    extern long double cephes_knl ( int,long double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::kn_, tag::cpu_,
                    (A0)(A1),
                    (arithmetic_<A0>)(arithmetic_<A1>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::kn_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : boost::result_of<meta::floating(A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      return nt2::cephes::kn((a0), type(a1));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::kn_, tag::cpu_,
                    (A0)(A1),
                    (double_<A0>)(double_<A1>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::kn_(tag::double_,tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : boost::result_of<meta::floating(A1)>{};

    NT2_FUNCTOR_CALL(2){ return cephes_kn(a0, a1); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::kn_, tag::cpu_,
                    (A0)(A1),
                    (float_<A0>)(float_<A1>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::kn_(tag::float_,tag::float_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : boost::result_of<meta::floating(A1)>{};

    NT2_FUNCTOR_CALL(2){ return cephes_knf(a0, a1); }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is long double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::kn_, tag::cpu_,
                    (A0)(A1),
                    (long double_<A0>)(long double_<A1>)
                   )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::kn_(tag::long double_,tag::long double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : boost::result_of<meta::floating(A1)>{};

    NT2_FUNCTOR_CALL(2){ return cephes_knl(a0, a1); }
  };
} }

#endif
// modified by jt the 26/12/2010