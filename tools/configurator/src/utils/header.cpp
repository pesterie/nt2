//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////

#include <utils/header.hpp>
#include <utils/license.hpp>
#include <boost/lexical_cast.hpp>
#include <cctype>
#include <cassert>

namespace nt2 { namespace config { namespace utils {
  
      header::header(std::string const& path, std::string const& name) : struct_name(name)
      {
        std::string full_path = path + name + ".hpp";
        if (h.is_open() == false)
        {
          h.open(full_path.c_str());
          h << NT2_LICENSE;
          
          std::string guard(NT2_CONCEPT_GUARD);
          int i = 0;
          while(name[i]) { (name[i] == '.') ? guard += '_' : guard += toupper(name[i]); ++i; }
          h << "#ifndef " << guard << "\n";
          h << "#define " << guard << "\n\n";
        }
      }

      int header::add_newline(void) 
      { 
        if(h.is_open() == true) { h << "\n"; return 0; }
        else return -1;
      }

      void header::add_include(std::string const& include)
      {
        includes.push_back(include);
      }
      
      void header::add_define(std::string const& name)
      {
        defines.push_back(name);
      }
      
      void header::add_macro(std::string const& name, std::string const& value)
      {
        macros.push_back(function(name,value));
      }

      void header::add_macro(std::string const& name, int const& value)
      {
        macros.push_back(function(name,boost::lexical_cast<std::string>(value)));
      }

      void header::add_typedef(std::string const& origin, std::string const& name)
      {
        std::string fullTypedef = "typedef " + origin + " " + name + ";\n";
        typedefs.push_back(fullTypedef);
      }

      void header::add_metafunction(std::string const& name, std::string const& static_value)
      {
        metafunctions.push_back(function(name,static_value));
      }

      void header::add_metafunction(std::string const& name, int const& static_value)
      {
        metafunctions.push_back(function(name,boost::lexical_cast<std::string>(static_value)));
      }

      void header::add_methode(std::string const& name, std::string const& value)
      {
        methodes.push_back(function(name,value));
      }

      void header::add_methode(std::string const& name, int const& value)
      {
        methodes.push_back(function(name,boost::lexical_cast<std::string>(value)));
      }

      int header::add(std::string const& s)
      {
        if(h.is_open() == true) { h << s; return 0;}
        else return -1;
      }

      int header::generate_class(void)
      {
        if(h.is_open() == true)
        {
          add_include("boost/mpl/int.hpp");
          //generate all includes
          for (int i = 0; i < includes.size(); ++i)
          {
            h << "#include <" << includes[i] << ">\n";
          }
          add_newline();

          //generate all defines
          for (int i = 0; i < defines.size(); ++i)
          {
            h << "#define " << defines[i] << "\n";
          }

          add_newline();
          h << "namespace nt2 { namespace platform {\n\n";
          h << "struct ";
          h << struct_name;
          h << "\n{\n";

          for (int i = 0; i < typedefs.size(); ++i)
          {
            h << "  " << typedefs[i] << "\n";  
          }

          //generate metafunctions
          
          for (int i = 0; i < metafunctions.size(); ++i)
          {
            h << "  typedef boost::mpl::int_<" << metafunctions[i].val  << "> " << metafunctions[i].name << ";\n";
          }

          //generate runtime functions
          for (int i = 0; i < methodes.size(); ++i)
          {
            h << "  inline int " << methodes[i].name << "(void) const { return " << methodes[i].val << "; }\n"; 
          }

          h << "};\n";
          add_newline();
          h << "} }\n";
          return 0;
        }
        else return -1;
      }

      header::~header()
      {
        if(h.is_open() == true)
        {
          h << "#endif"; 
          h.close();
        }
     }

} } }
