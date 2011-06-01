//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_HYPERBOLIC_FUNCTION_ASECH1M_HPP_INCLUDED
#define NT2_TOOLBOX_HYPERBOLIC_FUNCTION_ASECH1M_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/hyperbolic/include.hpp>

namespace nt2 {
  namespace tag
  {
    struct asech1m_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::asech1m_, asech1m, 1)
}

#include <nt2/toolbox/hyperbolic/function/scalar/asech1m.hpp>
#include <nt2/toolbox/hyperbolic/function/simd/all/asech1m.hpp> 

#endif
