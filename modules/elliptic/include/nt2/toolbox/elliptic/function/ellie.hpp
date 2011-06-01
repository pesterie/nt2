//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ELLIPTIC_FUNCTION_ELLIE_HPP_INCLUDED
#define NT2_TOOLBOX_ELLIPTIC_FUNCTION_ELLIE_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/elliptic/include.hpp>

namespace nt2 { namespace tag
  {         
    struct ellie_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::ellie_, ellie, 2)
}
 
#include <nt2/toolbox/elliptic/function/scalar/ellie.hpp>
#include <nt2/toolbox/elliptic/function/simd/all/ellie.hpp> 

 
#endif

// modified by jt the 25/12/2010