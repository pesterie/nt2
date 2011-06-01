//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTION_COSPI_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTION_COSPI_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/crlibm/include.hpp>

namespace nt2 { namespace crlibm { namespace tag
  {         
    template <class T > struct cospi_ {};
  }
  NT2_CRLIBM_FUNCTION_IMPLEMENTATION_TPL(cospi, 1)
  } }
 
#include <nt2/toolbox/crlibm/function/scalar/cospi.hpp>
// #include <nt2/toolbox/crlibm/function/simd/all/cospi.hpp> 

 
#endif

// modified by jt the 29/12/2010