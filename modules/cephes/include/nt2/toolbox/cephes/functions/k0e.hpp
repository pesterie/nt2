//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CEPHES_FUNCTIONS_K0E_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTIONS_K0E_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

namespace nt2 { namespace cephes { namespace tag
  {         
    struct k0e_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(cephes::tag::k0e_, k0e, 1)
  } }
 
#include <nt2/toolbox/cephes/functions/scalar/k0e.hpp>
// #include <nt2/toolbox/cephes/functions/simd/all/k0e.hpp> 

 
#endif

// modified by jt the 29/12/2010