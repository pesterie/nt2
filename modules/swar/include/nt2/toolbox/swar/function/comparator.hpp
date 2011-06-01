//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_SWAR_FUNCTION_COMPARATOR_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTION_COMPARATOR_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/swar/include.hpp>

namespace nt2 {
  struct ascending_ {};
  struct descending_{};
  namespace tag
  {         
    struct comparator_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::comparator_, comparator, 3)
}
 
#include <nt2/toolbox/swar/function/scalar/comparator.hpp>
#include <nt2/toolbox/swar/function/simd/all/comparator.hpp> 

 
#endif

// modified by jt the 25/12/2010