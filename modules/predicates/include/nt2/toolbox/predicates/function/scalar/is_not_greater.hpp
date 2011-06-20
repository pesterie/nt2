//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_GREATER_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_GREATER_HPP_INCLUDED
#include <nt2/include/functions/is_nan.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_greater_, tag::cpu_,
                        (A0)(A1),
                        (arithmetic_<A0>)(arithmetic_<A1>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_greater_(tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(2)
    {
       return a0 <= a1;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_greater_, tag::cpu_,
                        (A0)(A1),
                        (real_<A0>)(real_<A1>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_greater_(tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(2)
    {
       return ((a0 <= a1) || is_nan(a0)|| is_nan(a1));
    }
  };
} }

#endif
