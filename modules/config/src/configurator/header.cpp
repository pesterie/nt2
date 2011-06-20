//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////

#include <nt2/sdk/config/configurator/header.hpp>
#include <nt2/sdk/config/configurator/license.hpp>
#include <cctype>

namespace nt2 { namespace config { namespace utils {
  
      header::header(){}

      int header::init(std::string const& path, std::string const& name)
      {
        std::string full_path = path + name;
        if (h.is_open() == false)
        {
          h.open(full_path.c_str());
          h << NT2_LICENSE;
          
          std::string guard(NT2_CONCEPT_GUARD);
          int i = 0;
          while(name[i]) { (name[i] == '.') ? guard += '_' : guard += toupper(name[i]); ++i; }
          h << "#ifndef " << guard << "\n";
          h << "#define " << guard << "\n";
          return 0;
        }
        else return 1;
      }

      void  header::close(void)
      {
        h << "#endif";
        h.close();
      }

      int header::add_newline(void) 
      { 
        if(h.is_open() == true) { h << "\n"; return 0; }
        else return 1;
      }

      int header::add_macro(std::string const& name, std::string const& value)
      {
        if(h.is_open() == true) 
        {
          h << "#define " << name << " " << value << "\n"; 
          return 0;
        }
        else return 1;
      }

      int header::add(std::string const& s)
      {
        if(h.is_open() == true) { h << s; return 0;}
        else return 1;
      }

      header::~header()
      {
        if(h.is_open() == true) h.close();
      }

} } }
