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
#include <nt2/sdk/config/configurator/gpu.hpp>      
#include <nt2/sdk/config/configurator/units.hpp>      
#include <nt2/sdk/config/infos.hpp>
#include <nt2/arch/setup.hpp>
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
      cf::utils::header runtime_concept(NT2_CONCEPT_GENERATE_PATH, "runtime_concept.hpp");
      // Generating Scalar Unit support
      cf::utils::generate_scalar_unit(NT2_CONCEPT_GENERATE_PATH, "scalar_unit.hpp");

      // Generating SIMD Unit support
      cf::utils::generate_simd_unit(NT2_CONCEPT_GENERATE_PATH, "simd_unit.hpp");

      // Detecting Multicore capabilities
      std::cout << "Detecting Multithreading capabilities...\n";
      int nb_cores = nt2::config::get_threads();
      if(nb_cores > 0) 
      {
        runtime_concept.add_macro("NB_CORES", nb_cores);
        std::cout << "-- Total cores found (Logical and Physical) : " << nb_cores << "\n";
      }
      else std::cerr << "-- Not a multicore architecture (Core test failed).\n";
      
      int nb_logical_cores_per_unit = nt2::config::get_logical_cores();
      if(nb_logical_cores_per_unit > 0) 
      {
        runtime_concept.add_macro("NB_LOGICAL_CORES_PER_UNIT", nb_logical_cores_per_unit);
      	std::cout << "-- Logical cores per unit found : " << nb_logical_cores_per_unit << "\n";
      }
      else std::cerr << "-- Not a multicore architecture (Logical Core test failed).\n";


      int nb_physical_cores = nt2::config::get_physical_cores();
      if(nb_physical_cores > 0) 
      {
        runtime_concept.add_macro("NB_PHYSICAL_CORES", nb_physical_cores);
        std::cout << "-- Physical cores found : " << nb_physical_cores << "\n";
      }
      else std::cerr << "-- Not a multicore architecture (Physical Core test failed).\n";

      // Getting cache specs
      nt2::config::cache_report cache;
      std::cout << "Detecting cache specifications...\n";
      if( nt2::config::get_cache_infos(cache) == 0)
      {
        if(cache.L1 > 0) 
        {
          runtime_concept.add_macro("L1_CACHE_SIZE", cache.L1);
          std::cout << "-- L1 cache size : " << cache.L1 << " kB\n";
        }
        if(cache.L2 > 0) 
        {  
          runtime_concept.add_macro("L2_CACHE_SIZE", cache.L2);
          std::cout << "-- L2 cache size : " << cache.L2 << " kB\n";
        }
        if(cache.L3 > 0) 
        {
          runtime_concept.add_macro("L3_CACHE_SIZE", cache.L3);
          std::cout << "-- L3 cache size : " << cache.L3 << " kB\n";
        }
        if(cache.l1 > 0)
        {
          runtime_concept.add_macro("L1_LINE_SIZE",  cache.l1);
          std::cout << "-- L1 cache line size : " << cache.l1 << " bytes\n";
        }
        if(cache.l2 > 0) 
        { 
          runtime_concept.add_macro("L1_LINE_SIZE",  cache.l2);
          std::cout << "-- L2 cache line size : " << cache.l2 << " bytes\n";
        }
        if(cache.l3 > 0) 
        {  
          runtime_concept.add_macro("L1_LINE_SIZE",  cache.l3);
          std::cout << "-- L3 cache line size : " << cache.l3 << " bytes\n";
        }

        int coh = nt2::config::get_cache_coherency_line_size(cache);
        if(coh > 0) runtime_concept.add_macro("COHERENCY_LINE_SIZE", coh);
      }
      else std::cout << "-- Getting cache specifications failed.";

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

      boost::array<const std::string,9> ext = {{"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"}};
      boost::array<const std::string,9> EXT = {{"HAS_SSE_SUPPORT","HAS_SSE2_SUPPORT","HAS_SSE3_SUPPORT",
                                              "HAS_SSSE3_SUPPORT","HAS_SSE4_1_SUPPORT","HAS_SSE4_2_SUPPORT",
                                              "HAS_AVX_SUPPORT","HAS_XOP_SUPPORT","HAS_FMA4_SUPPORT"}};


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
