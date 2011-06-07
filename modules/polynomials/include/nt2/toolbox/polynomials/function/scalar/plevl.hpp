//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_POLYNOMIALS_FUNCTION_SCALAR_PLEVL_HPP_INCLUDED
#define NT2_TOOLBOX_POLYNOMIALS_FUNCTION_SCALAR_PLEVL_HPP_INCLUDED
#include <nt2/include/functions/tchebeval.hpp>
#include <nt2/include/functions/fma.hpp>
#include <nt2/sdk/meta/fusion.hpp>
#include <boost/fusion/adapted/array.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::plevl_, tag::cpu_,
                       (A0)(A1),
                       (arithmetic_<A0>)(fusion_sequence_<A1>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::plevl_(tag::arithmetic_,tag::fusion_sequence_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> :
      meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      return plevl(type(a0), a1);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::plevl_, tag::cpu_,
                       (A0)(A1),
                       (real_<A0>)(fusion_sequence_<A1>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::plevl_(tag::real_,tag::fusion_sequence_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> :
      meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typename A1::const_iterator p = a1.begin();
      A0 ans = a0+*p++;
      do
      ans = fma(ans, a0, *p);
      while( ++p !=  a1.end());
      return ans;
    }
  };
} }

#endif
// modified by jt the 26/12/2010
// modified manually by jt the 26/12/2010
