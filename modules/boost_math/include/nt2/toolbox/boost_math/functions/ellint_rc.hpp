//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_ELLINT_RC_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_ELLINT_RC_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <boost/math/special_functions/ellint_rc.hpp>

namespace nt2 { namespace boost_math { namespace tag
  {         
    struct ellint_rc_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(boost_math::tag::ellint_rc_, ellint_rc, 2)
  } }
 
#include <nt2/toolbox/boost_math/functions/scalar/ellint_rc.hpp>
// #include <nt2/toolbox/boost_math/functions/simd/all/ellint_rc.hpp> 

 
#endif

// modified by jt the 29/12/2010