//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_SDK_CONFIG_CONFIGURATOR_UNITS_HPP
#define NT2_SDK_CONFIG_CONFIGURATOR_UNITS_HPP

#include <string>

namespace nt2 { namespace config { namespace utils {

  void generate_scalar_unit(std::string const& path, std::string const& name);
  void generate_simd_unit(std::string const& path, std::string const& name);

} } }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_UNITS_HPP */
