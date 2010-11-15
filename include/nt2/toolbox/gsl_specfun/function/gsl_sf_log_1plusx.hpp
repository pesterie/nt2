//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_GSL_SF_LOG_1PLUSX_HPP_INCLUDED
#define NT2_TOOLBOX_GSL_SPECFUN_FUNCTION_GSL_SF_LOG_1PLUSX_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/gsl_specfun/include.hpp>

namespace nt2 { namespace gsl_specfun
  {	       
    struct gsl_sf_log_1plusx_ {};
    NT2_FUNCTION_IMPLEMENTATION(gsl_specfun::gsl_sf_log_1plusx_, gsl_sf_log_1plusx, 1)
  }
}
 
#include <nt2/toolbox/gsl_specfun/function/scalar/gsl_sf_log_1plusx.hpp>
// #include NT2_GSL_SPECFUN_INCLUDE(gsl_sf_log_1plusx.hpp) 

 
#endif
