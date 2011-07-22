//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_SDK_CONFIG_CONFIGURATOR_HEADER_HPP
#define NT2_SDK_CONFIG_CONFIGURATOR_HEADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

namespace nt2 { namespace config { namespace utils {

  class header
  {
  public:
    header(std::string const& path, std::string const& name);
    ~header();
    int add_newline(void);
    int add_include(std::string const& include);
    int add_define(std::string const& name);
    int add_macro(std::string const& name, std::string const& value);
    int add_macro(std::string const& name, int const& value);
    int add_typedef(std::string const& origin, std::string const& name);
    int add(std::string const& s); 
    int generate_class(void);

  protected:
    void add_function(std::string const& name, std::string const& value);
    void add_function(std::string const& name, int const& value);
    
  private:

    struct function
    {
      function() {}
      function(function const& f) : upper(f.upper), lower(f.lower), value(f.value) {}
      function(std::string up, std::string low, std::string val)
        : upper(up), lower(low), value(val) {}
      function operator=(const function& f)
      {
        this->upper = f.upper;
        this->lower = f.lower;
        this->value = f.value;
        return *this;
      }
      std::string upper;
      std::string lower;
      std::string value;
    };

    std::vector<std::string> typedefs; 
    std::vector<function> functions;
    std::ofstream h;
    std::string struct_name;
  };

} } }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_HEADER_HPP */
