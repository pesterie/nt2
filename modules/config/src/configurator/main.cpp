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
#include <nt2/sdk/config/configurator/header.hpp>
#include <nt2/sdk/config/configurator/gpu.hpp>      
#include <nt2/sdk/config/configurator/units.hpp>      
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
  

    if(vm.count("runtime_gen")) 
    {
      // Generating Scalar Unit support
      cf::utils::generate_scalar_unit(NT2_CONCEPT_GENERATE_PATH, "scalar_unit");

      // Generating SIMD Unit support
      cf::utils::generate_simd_unit(NT2_CONCEPT_GENERATE_PATH, "simd_unit");

      //Generating Memory hierarchie
      cf::utils::generate_memory_hierarchy(NT2_CONCEPT_GENERATE_PATH, "memory_hierarchy");

      //Generating Memory hierarchie
      cf::utils::generate_core_unit(NT2_CONCEPT_GENERATE_PATH, "core_unit");


      std::cout << "Detecting GPU devices specifications...\n";
      nt2::config::gpu_report gpu;
      int result = nt2::config::get_gpu_devices_properties(gpu);
      if(gpu.size() != 0) 
      {
        for(int idx = 0; idx < gpu.size(); ++idx)
        {
          
        }
      }
      else std::cerr << "No GPU Devices detected!\n";
     
    }
    else if(vm.count("manual_gen"))
    {
      // TODO
    }
    else if(vm.count("default"))
    {
      // cf::utils::header bootstrap(NT2_CONCEPT_DEFAULT_PATH, "bootstrap.hpp");

      // boost::array<const std::string,9> ext = {{"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"}};
      // boost::array<const std::string,9> EXT = {{"HAS_SSE_SUPPORT","HAS_SSE2_SUPPORT","HAS_SSE3_SUPPORT",
      //                                         "HAS_SSSE3_SUPPORT","HAS_SSE4_1_SUPPORT","HAS_SSE4_2_SUPPORT",
      //                                         "HAS_AVX_SUPPORT","HAS_XOP_SUPPORT","HAS_FMA4_SUPPORT"}};


      // // Detecting SIMD extensions
      // for(int i = 0; i < 9; ++i)
      // {
      //   if (nt2::config::has_vectorial_extension(ext[i]))
      //   {
      //     bootstrap.add_define(EXT[i]);
      //   }
      // }

      // bootstrap.add_define("HAS_DEFAULT_CONCEPT");
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
