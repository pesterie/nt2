//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_FUZZY_FUNCTION_SIMD_COMMON_DEFINITELY_GREATER_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTION_SIMD_COMMON_DEFINITELY_GREATER_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_ord.hpp>
#include <nt2/include/functions/successor.hpp>
#include <nt2/include/functions/abs.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::definitely_greater_, tag::cpu_,
                                     (A0)(X),
                                     ((simd_<arithmetic_<A0>,X>))
                                     ((simd_<arithmetic_<A0>,X>))
                                     ((simd_<arithmetic_<A0>,X>))
                                    );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::definitely_greater_(tag::simd_(tag::arithmetic_, X),
                                       tag::simd_(tag::arithmetic_, X),
                                       tag::simd_(tag::arithmetic_, X)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A0,A1)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(3)
    {
      return isgt(a0, a1+abs(a2));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::definitely_greater_, tag::cpu_,
                                     (A0)(X),
                                     ((simd_<real_<A0>,X>))
                                     ((simd_<real_<A0>,X>))
                                     ((simd_<real_<A0>,X>))
                                    );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::definitely_greater_(tag::simd_(tag::real_, X),
                                       tag::simd_(tag::real_, X),
                                       tag::simd_(tag::real_, X)),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A0,A1)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(3)
    {
      return b_and(
               isord(a0, a1),
               isgt(a0, successor(a1, a2))
               );
    }
  };
} }

#endif
// modified by jt the 05/01/2011