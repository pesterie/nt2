//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_POW_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_POW_HPP_INCLUDED
#include <nt2/include/functions/powi.hpp>
#include <nt2/include/functions/abs.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::pow_, tag::cpu_,
                     (A0)(A1),
                     (arithmetic_<A0>)(arithmetic_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::pow_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      return nt2::powi(type(a0), a1);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::pow_, tag::cpu_,
                     (A0)(A1),
                     (double_<A0>)(double_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::pow_(tag::double_,tag::double_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      bool ltza0 = a0 < Zero<A0>(); 
      if ((a0 == a1 && a0 == Minf<A0>()) ||
	  (ltza0 && !is_flint(a1))
	  ) return Nan<A0>(); 
      A0 res =  ::pow(nt2::abs(a0), a1);
      return  (ltza0) ? -res : res; 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::pow_, tag::cpu_,
                     (A0)(A1),
                     (float_<A0>)(float_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::pow_(tag::float_,tag::float_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      meta::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL(2)
    {
      bool ltza0 = a0 < Zero<A0>(); 
      if ((a0 == a1 && a0 == Minf<A0>()) ||
	  (ltza0 && !is_flint(a1))
	  ) return Nan<A0>(); 
      A0 res =  ::powf(nt2::abs(a0), a1);
      return  (ltza0) ? -res : res; 
    }
  };
} }

#endif
// modified by jt the 26/12/2010
