//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_STANDARD_FUNCTIONS_FREXP_HPP_INCLUDED
#define NT2_TOOLBOX_STANDARD_FUNCTIONS_FREXP_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

namespace nt2 { namespace standard { namespace tag
  {         
    struct frexp_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(standard::tag::frexp_, frexp, 1)
  NT2_FUNCTION_IMPLEMENTATION_TPL(standard::tag::frexp_, frexp, (A0 const&)(A1&), 2)
  } }
 
#include <nt2/toolbox/standard/functions/scalar/frexp.hpp>
// #include <nt2/toolbox/standard/functions/simd/all/frexp.hpp> 

 
#endif

// modified by jt the 29/12/2010
