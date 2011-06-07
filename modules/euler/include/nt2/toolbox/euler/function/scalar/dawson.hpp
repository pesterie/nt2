//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EULER_FUNCTION_SCALAR_DAWSON_HPP_INCLUDED
#define NT2_TOOLBOX_EULER_FUNCTION_SCALAR_DAWSON_HPP_INCLUDED
#include <nt2/include/constants/real.hpp>
#include <nt2/include/functions/plevl.hpp>
#include <nt2/include/functions/polevl.hpp>

#include <nt2/include/functions/copysign.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/rec.hpp>
#include <boost/array.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::dawson_, tag::cpu_,
                        (A0),
                        (arithmetic_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::dawson_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :  meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_RETURN_TYPE(1)::type type;
      return nt2::dawson(type(a0));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::dawson_, tag::cpu_,
                        (A0),
                        (real_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::dawson_(tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :  meta::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      static const boost::array<A0, 10 > AN = {{
      1.13681498971755972054E-11,
      8.49262267667473811108E-10,
      1.94434204175553054283E-8,
      9.53151741254484363489E-7,
      3.07828309874913200438E-6,
      3.52513368520288738649E-4,
      -8.50149846724410912031E-4,
      4.22618223005546594270E-2,
      -9.17480371773452345351E-2,
      9.99999999999999994612E-1,
      }};
      static const boost::array<A0, 11 > AD = {{
      2.40372073066762605484E-11,
      1.48864681368493396752E-9,
      5.21265281010541664570E-8,
      1.27258478273186970203E-6,
      2.32490249820789513991E-5,
      3.25524741826057911661E-4,
      3.48805814657162590916E-3,
      2.79448531198828973716E-2,
      1.58874241960120565368E-1,
      5.74918629489320327824E-1,
      1.00000000000000000539E0,
      }};

      /* interval 3.25 to 6.25 */
      static const boost::array<A0 , 11 >BN = {{
      5.08955156417900903354E-1,
      -2.44754418142697847934E-1,
      9.41512335303534411857E-2,
      -2.18711255142039025206E-2,
      3.66207612329569181322E-3,
      -4.23209114460388756528E-4,
      3.59641304793896631888E-5,
      -2.14640351719968974225E-6,
      9.10010780076391431042E-8,
      -2.40274520828250956942E-9,
      3.59233385440928410398E-11,
      }};
      static  const boost::array<A0, 10>BD = {{
      /*  1.00000000000000000000E0,*/
      -6.31839869873368190192E-1,
      2.36706788228248691528E-1,
      -5.31806367003223277662E-2,
      8.48041718586295374409E-3,
      -9.47996768486665330168E-4,
      7.81025592944552338085E-5,
      -4.55875153252442634831E-6,
      1.89100358111421846170E-7,
      -4.91324691331920606875E-9,
      7.18466403235734541950E-11,
      }};

      /* 6.25 to infinity */
      static  const boost::array<A0, 5> CN = {{
      -5.90592860534773254987E-1,
      6.29235242724368800674E-1,
      -1.72858975380388136411E-1,
      1.64837047825189632310E-2,
      -4.86827613020462700845E-4,
      }};
      static  const boost::array<A0, 5> CD = {{
      /* 1.00000000000000000000E0,*/
      -2.69820057197544900361E0,
      1.73270799045947845857E0,
      -3.93708582281939493482E-1,
      3.44278924041233391079E-2,
      -9.73655226040941223894E-4,
      }};
      A0 xx =  nt2::abs(a0);
      A0 x = sqr(xx);
      if( xx < 3.25 )
      {
        A0 x = sqr(xx);
        return a0 * polevl( x, AN)/polevl( x, AD );
      }
      x =  rec(x);
      if( xx < 6.25 )
      {
        A0 y = rec(xx) + x * polevl( x, BN) / (plevl( x, BD) * xx);
        return copysign(Half<A0>()*y, a0);
      }
      if( xx > 1.0e9 ) return Half<A0>()*copysign(rec(xx), a0);
      /* 6.25 to 1.0e9 */
      A0 y = rec(xx) + x * polevl( x, CN) / (plevl( x, CD) * xx);
      return copysign(Half<A0>()*y, a0);
    }
  };
} }

#endif
// modified by jt the 26/12/2010