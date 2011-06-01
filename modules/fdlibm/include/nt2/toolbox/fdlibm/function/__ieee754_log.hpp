//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTION__IEEE754_LOG_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTION__IEEE754_LOG_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/fdlibm/include.hpp>

namespace nt2 { namespace fdlibm { namespace tag
  {         
    struct __ieee754_log_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(fdlibm::tag::__ieee754_log_, __ieee754_log, 1)
  } }
 
#include <nt2/toolbox/fdlibm/function/scalar/__ieee754_log.hpp>
// #include <nt2/toolbox/fdlibm/function/simd/all/__ieee754_log.hpp> 

 
#endif

// modified by jt the 29/12/2010