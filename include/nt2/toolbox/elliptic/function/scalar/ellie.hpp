//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ELLIPTIC_FUNCTION_SCALAR_ELLIE_HPP_INCLUDED
#define NT2_TOOLBOX_ELLIPTIC_FUNCTION_SCALAR_ELLIE_HPP_INCLUDED
#include <boost/math/special_functions.hpp>
#include <nt2/sdk/constant/eps_related.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/digits.hpp>

#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/tan.hpp>
#include <nt2/include/functions/atan.hpp>
#include <nt2/include/functions/average.hpp>
#include <nt2/include/functions/ellpe.hpp>
#include <nt2/include/functions/ellpk.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for ellie

  /////////////////////////////////////////////////////////////////////////////
  // Compute ellie(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<ellie_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : 
      boost::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (3, (float,double,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,       float)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type type;
      if (a1>One<A1>()||(isltz(a1))) return Nan<type>(); 
      else if (iseqz(a1))
	return a0;
      else if (a1 == One<A1>())
	return nt2::sin(a0); 
      else
	{
	  type lphi = nt2::abs(a0);
	  type m   =  a1; 
	  type a = One<type>();
	  type b = nt2::sqrt(oneminus(m));
	  type c = nt2::sqrt(m);
	  int d = One<int>();
	  type e = Zero<type>();
	  type t = nt2::tan( lphi );
	  int mod = (lphi + Pio_2<type>())/Pi<type>();
	  while( nt2::abs(c) > Eps<type>()*nt2::abs(a) )
	    {
	      type temp = b/a;
	      lphi = lphi + nt2::atan(t*temp) + mod * Pi < type>();
	      mod = (lphi + Pio_2<type>())/Pi<type>();
	      t *= oneplus(temp)/( oneminus(temp * sqr(t)));
	      c = average(a,-b);
	      temp = nt2::sqrt(a*b);
	      a = nt2::average(a,b);
	      b = temp;
	      d += d;
	      e += c*nt2::sin(lphi);
	    }
	  
	  b = oneminus(m);
	  type temp = nt2::ellpe(b)/nt2::ellpk(b);
	  temp *= (nt2::atan(t) + mod * Pi < float>())/(d * a);
	  temp += e;
	  if(isltz(a0))  temp = -temp;
	  return temp ;
	}
      }
    
    NT2_FUNCTOR_CALL_EVAL_IF(2, double)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type type;
      if (a1>One<A1>()||(isltz(a1))) return Nan<type>(); 
      if (iseqz(a1))  return type(a0);
      return boost::math::ellint_2(nt2::sqrt(type(a1)), type(a0));
    }
    
    NT2_FUNCTOR_CALL_EVAL_IF(2,       arithmetic_)
    {
	typedef typename NT2_CALL_RETURN_TYPE(2)::type type;
	return nt2::ellie(type(a0), type(a1)); 
    }
  
  };
} }


      
#endif