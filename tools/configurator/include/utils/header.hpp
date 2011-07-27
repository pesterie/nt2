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

    void add_include(std::string const& include);
    void add_define(std::string const& name);
    void add_macro(std::string const& name, std::string const& value);
    void add_macro(std::string const& name, int const& value);
    void add_typedef(std::string const& origin, std::string const& name);
    void add_metafunction(std::string const& name, std::string const& static_value);
    void add_metafunction(std::string const& name, int const& stadtic_value);
    void add_methode(std::string const& name, std::string const& value);
    void add_methode(std::string const& name, int const& value);
    int  generate_class(void);

  protected :
    int add_newline(void);    
    int add(std::string const& s);     
    
  private:

    struct function
    {
      function() {}
      function(function const& f) : name(f.name), val(f.val) {}
      function(std::string name_, std::string val_)
        : name(name_), val(val_) {}
      function operator=(const function& f)
      {
        this->name = f.name;
        this->val  = f.val;
        return *this;
      }
      std::string name;
      std::string val;
    };

    std::vector<std::string> includes; 
    std::vector<std::string> defines; 
    std::vector<std::string> typedefs; 
    std::vector<function> macros;
    std::vector<function> metafunctions;
    std::vector<function> methodes;
    std::ofstream h;
    std::string struct_name;
  };

} } }

#endif /* NT2_SDK_CONFIG_CONFIGURATOR_HEADER_HPP */
