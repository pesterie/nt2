//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NEZ_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NEZ_HPP_INCLUDED



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_nez_, tag::cpu_,
                        (A0),
                        (fundamental_<A0>)
                       )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_nez_(tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
       return a0 != 0;
    }
  };
} }

#endif
