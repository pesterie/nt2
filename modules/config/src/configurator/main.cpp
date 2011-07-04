//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <boost/program_options.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <string>
#include <nt2/sdk/config/configurator/cache.hpp>
#include <nt2/sdk/config/configurator/cpuid.hpp>
#include <nt2/sdk/config/configurator/utils.hpp>
#include <nt2/sdk/config/configurator/core.hpp>
#include <nt2/sdk/config/configurator/simd.hpp>
#include <nt2/sdk/config/configurator/header.hpp>
#include <nt2/sdk/config/infos.hpp>
#include <iterator>
#include <cassert>
#include <cctype>

namespace po = boost::program_options;
namespace cf = nt2::config;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Entry point for the configurator
// Documentation: http://nt2.lri.fr/sdk/configurator.html
////////////////////////////////////////////////////////////////////////////////

int main(int ac, char *av[])
{
  try {
    
    po::options_description desc("Configurator options");
    desc.add_options()
      ("runtime_gen", "Test your hardware specifications and generate the Architecture Concept")
      ("manual_gen" , "Manuel genration of the Architecture Concept")
      ("default"    , "Default generation of bootstrap")
      ("help"       , "Start help")
      ;
    
    po::variables_map vm;        
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);  
  
    boost::array<const std::string,9> ext = {{"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"}};
    boost::array<const std::string,9> EXT = {{"HAS_SSE_SUPPORT","HAS_SSE2_SUPPORT","HAS_SSE3_SUPPORT",
                                              "HAS_SSSE3_SUPPORT","HAS_SSE4_1_SUPPORT","HAS_SSE4_2_SUPPORT",
                                              "HAS_AVX_SUPPORT","HAS_XOP_SUPPORT","HAS_FMA4_SUPPORT"}};

    if(vm.count("runtime_gen")) 
    {
      // Detecting SIMD extensions
      cf::utils::header runtime_concept(NT2_CONCEPT_GENERATE_PATH, "runtime_detection.hpp");

      // Detecting SIMD extensions
      for(int i = 0; i < 9; ++i)
      {
        if (nt2::config::has_vectorial_extension(ext[i]))
        {
          runtime_concept.add_define(EXT[i]);
        }
      }
   
      int nb_cores = nt2::config::get_threads();
      if(nb_cores > 0) runtime_concept.add_macro("NB_CORES", nb_cores);
      int nb_logical_cores_per_unit = nt2::config::get_logical_cores();
      if(nb_logical_cores_per_unit > 0) runtime_concept.add_macro("NB_LOGICAL_CORES_PER_UNIT", nb_logical_cores_per_unit);
      int nb_physical_cores = nt2::config::get_physical_cores();
      if(nb_physical_cores > 0) runtime_concept.add_macro("NB_PHYSICAL_CORES", nb_physical_cores);

      nt2::config::cache_report cache;
      nt2::config::get_cache_infos(cache);
      if(nb_physical_cores > 0) runtime_concept.add_macro("NB_PHYSICAL_CORES", nb_physical_cores);

      int coh = nt2::config::get_cache_coherency_line_size(cache);
      

      runtime_concept.add_define("HAS_RUNTIME_GEN_CONCEPT");
      runtime_concept.generate_class();
    }
    else if(vm.count("manual_gen"))
    {
      // TODO
    }
    else if(vm.count("default"))
    {
      cf::utils::header bootstrap(NT2_CONCEPT_DEFAULT_PATH, "bootstrap.hpp");

      // Detecting SIMD extensions
      for(int i = 0; i < 9; ++i)
      {
        if (nt2::config::has_vectorial_extension(ext[i]))
        {
          bootstrap.add_define(EXT[i]);
        }
      }

      bootstrap.add_define("HAS_DEFAULT_CONCEPT");
    }
    else if(vm.count("help"))
    {
      cout << "TODO : Write help.\n";
    }
    else {
      cout << "Add option --help for more infos about the configurator.\n";
    }
  }
  catch(exception& e) {
    cerr << "error: " << e.what() << "\n";
    return 1;
  }
  catch(...) {
    cerr << "Exception of unknown type!\n";
  }

  return 0;
}
