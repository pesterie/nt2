//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_CRLIBM_FUNCTIONS_TANPI_RU_HPP_INCLUDED
#define NT2_TOOLBOX_CRLIBM_FUNCTIONS_TANPI_RU_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/crlibm/specific/tags.hpp>

namespace nt2 { namespace crlibm { namespace tag
  {
    struct tanpi_ru_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(crlibm::tag::tanpi_ru_, tanpi_ru, 1)
} }

#endif
