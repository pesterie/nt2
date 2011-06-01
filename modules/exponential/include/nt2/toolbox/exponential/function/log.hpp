//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_LOG_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_LOG_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/exponential/include.hpp>

namespace nt2 { namespace tag
  {         
    struct log_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::log_, log, 1)
}
 
#include <nt2/toolbox/exponential/function/scalar/log.hpp>
#include <nt2/toolbox/exponential/function/simd/all/log.hpp> 

 
#endif

// modified by jt the 25/12/2010