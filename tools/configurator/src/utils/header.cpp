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
        else return 1;
      }

      int header::add_include(std::string const& include)
      {
        if(h.is_open() == true) 
        {
          h << "#include <" << include << ">\n";
          return 0;
        }
        else return 1;
      }
      
      int header::add_define(std::string const& name)
      {
        if(h.is_open() == true) 
        {
          h << "#define NT2_" << name << "\n"; 
          return 0;
        }
        else return 1;
      }

      void header::add_function(std::string const& name, std::string const& value)
      {
        std::string temp;
        int i = 0;
        while(name[i]) { temp.push_back(tolower(name[i])); ++i; }
        functions.push_back(function(name,temp,value));
      }
      
      void header::add_function(std::string const& name, int const& value)
      {
        std::string temp;
        int i = 0;
        while(name[i]) { temp.push_back(tolower(name[i])); ++i; }
        functions.push_back(function(name,
                                     temp,
                                     boost::lexical_cast<std::string>(value)
                                     )
                            );
      }
      
      int header::add_macro(std::string const& name, std::string const& value)
      {
        if(h.is_open() == true) 
        {
          h << "#define NT2_" << name << " " << value << "\n"; 
          add_function(name, value);
          return 0;
        }
        else return 1;
      }

      int header::add_macro(std::string const& name, int const& value)
      {
        if(h.is_open() == true) 
        {
          h << "#define NT2_" << name << " " << value << "\n";
          add_function(name, value);
          return 0;
        }
        else return 1;
      }

      int header::add_typedef(std::string const& origin, std::string const& name)
      {
        if(h.is_open() == true) 
        {
          std::string full_typedef = "typedef " + origin + " " + name + ";\n";
          typedefs.push_back(full_typedef);
          return 0;
        }
        else return 1;
      }


      int header::add(std::string const& s)
      {
        if(h.is_open() == true) { h << s; return 0;}
        else return 1;
      }

      int header::generate_class(void)
      {
        if(h.is_open() == true)
        {
          add_newline();
          add_include("boost/mpl/int.hpp");
          add_newline();
          h << "namespace nt2 { namespace arch {\n\n";
          h << "struct ";
          h << struct_name;
          h << "\n{\n";

          for (int i = 0; i < typedefs.size(); ++i)
          {
            h << "  " << typedefs[i] << "\n";  
          }

          //generate metafunctions and runtime functions
          for (int i = 0; i < functions.size(); ++i)
          {
            h << "  typedef boost::mpl::int_<" << functions[i].upper  << "> " << functions[i].lower << ";\n";
            h << "  int get_" << functions[i].lower << "(void) { return " << functions[i].lower << "(); }\n"; 
          }
          h << "};\n";
          add_newline();
          h << "} }\n";
          return 0;
        }
        else return 1;
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
