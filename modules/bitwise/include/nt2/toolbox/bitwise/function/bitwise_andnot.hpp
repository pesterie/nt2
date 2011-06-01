//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/bitwise/include.hpp>

namespace nt2 { namespace tag
  {         
    struct bitwise_andnot_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::bitwise_andnot_, bitwise_andnot, 2)
  NT2_FUNCTION_IMPLEMENTATION(tag::bitwise_andnot_, b_andnot, 2)
}
 
#include <nt2/toolbox/bitwise/function/scalar/bitwise_andnot.hpp>
#include <nt2/toolbox/bitwise/function/simd/all/bitwise_andnot.hpp> 

#include <nt2/toolbox/bitwise/recognition/bitwise_andnot.hpp>
 
#endif

// modified by jt the 25/12/2010
