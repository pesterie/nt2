//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_GSL_SPECFUN_FUNCTIONS_GSL_SF_BESSEL_YN_HPP_INCLUDED
#define NT2_TOOLBOX_GSL_SPECFUN_FUNCTIONS_GSL_SF_BESSEL_YN_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

namespace nt2 { namespace gsl_specfun { namespace tag
  {         
    struct gsl_sf_bessel_yn_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(gsl_specfun::tag::gsl_sf_bessel_yn_, gsl_sf_bessel_yn, 2)
  } }
 
#include <nt2/toolbox/gsl_specfun/functions/scalar/gsl_sf_bessel_yn.hpp>
// #include <nt2/toolbox/gsl_specfun/functions/simd/all/gsl_sf_bessel_Yn.hpp> 

 
#endif

// modified by jt the 29/12/2010