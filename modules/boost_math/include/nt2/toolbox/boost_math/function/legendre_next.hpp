//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTION_LEGENDRE_NEXT_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTION_LEGENDRE_NEXT_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <boost/math/special_functions/legendre.hpp>

namespace nt2 { namespace boost_math { namespace tag
  {         
    struct legendre_next_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(boost_math::tag::legendre_next_, legendre_next, 5)
  } }
 
#include <nt2/toolbox/boost_math/function/scalar/legendre_next.hpp>
// #include <nt2/toolbox/boost_math/function/simd/all/legendre_next.hpp> 

 
#endif

// modified by jt the 29/12/2010
