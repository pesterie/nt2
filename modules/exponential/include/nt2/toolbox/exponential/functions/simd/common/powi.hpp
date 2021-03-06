//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_SIMD_COMMON_POWI_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_SIMD_COMMON_POWI_HPP_INCLUDED
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/bitofsign.hpp>
#include <nt2/include/functions/signnz.hpp>
#include <nt2/include/functions/is_odd.hpp>
#include <nt2/include/functions/is_even.hpp>
#include <nt2/include/functions/fma.hpp>
#include <nt2/include/functions/shri.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/any.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::powi_, tag::cpu_
                            , (A0)(A1)(X)
                            , ((simd_<arithmetic_<A0>,X>))(scalar_< integer_<A1> >)
                            )
  {

    typedef typename meta::as_real<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return powi(a0, tofloat(a1)); 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is real_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::powi_, tag::cpu_
                            , (A0)(A1)(X)
                            , ((simd_<real_<A0>,X>))(scalar_< integer_<A1> >)
                            )
  {

    typedef typename meta::strip<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
	typedef result_type r_type;
        r_type sign_x = bitofsign(a0);
        r_type x = b_xor(a0, sign_x);//x = nt2::abs(a0)
	if (is_even(a1)) sign_x = Zero<r_type>(); 
        A1 n = nt2::abs(a1);
        r_type ret = One<r_type>();
        for(A1 t = n; t > 0; t >>= 1)
        {
	  if(is_odd(t)) ret*=x;
	  x = sqr(x);
        }
        x =  b_xor(ret, sign_x);
	return is_ltz(a1) ? rec(x) : x; 
    }
  };
} }


#endif
