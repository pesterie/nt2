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
void test(void);

////////////////////////////////////////////////////////////////////////////////
// Entry point for the configurator
// Documentation: http://nt2.lri.fr/sdk/configurator.html
////////////////////////////////////////////////////////////////////////////////

int main(int ac, char *av[])
{
  try {
    
    po::options_description desc("Configurator options");
    desc.add_options()
      ("runtime_gen", "Test your hardware specifications and display the result")
      ("runtime_gen", "Test your hardware specifications and generate the Architecture Concept")
      ("hwloc_gen"  , "Test your hardware specifications with HWLOC and generate the Architecture Concept")
      ("manual_gen" , "Manuel genration of the Architecture Concept")
      ("default"    , "Default generation of bootstrap")
      ("help"       , "Start help")
      ;
    
    po::variables_map vm;        
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);    

    if(vm.count("runtime_test")) 
    {
      test();
      return 1;
    }
    else if(vm.count("hwloc_gen"))
    {
      // TODO
    }
    else if(vm.count("manual_gen"))
    {
      // TODO
    }
    else if(vm.count("default"))
    {
      cf::utils::header bootstrap;
      bootstrap.init(NT2_CONCEPT_DEFAULT_PATH, "bootstrap.hpp");

      boost::array<const std::string,9> ext = {{"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"}};
      boost::array<const std::string,9> EXT = {{"NT2_HAS_SSE_SUPPORT","NT2_HAS_SSE2_SUPPORT","NT2_HAS_SSE3_SUPPORT",
                                                "NT2_HAS_SSSE3_SUPPORT","NT2_HAS_SSE4_1_SUPPORT","NT2_HAS_SSE4_2_SUPPORT",
                                                "NT2_HAS_AVX_SUPPORT","NT2_HAS_XOP_SUPPORT","NT2_HAS_FMA4_SUPPORT"}};
      for(int i = 0; i < 9; ++i)
      {
        if (nt2::config::has_vectorial_extension(ext[i]))
        {
          bootstrap.add_macro(EXT[i], "");
        }
      }

      bootstrap.add_macro("NT2_HAS_DEFAULT_CONCEPT", "");
      bootstrap.close();
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

void test(void)
{
  boost::array<std::string,9> ext = { {"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"} };

  std::cout << "===============================" << std::endl;
  std::cout << "Threads (logical cores per physical cores) : " << nt2::config::get_threads() << std::endl;
  std::cout << "Logical Cores : " << nt2::config::get_logical_cores() << std::endl;
  std::cout << "Cores : " << nt2::config::get_physical_cores() << std::endl;

  nt2::config::cache_report cache;
  nt2::config::get_cache_infos(cache);
  int coh = nt2::config::get_cache_coherency_line_size(cache);

  std::cout << "===============================" << std::endl;
  std::cout << "Cache size : " << std::endl;
  std::cout << "  L1 = : " << cache.L1 << std::endl;
  std::cout << "  L2 = : " << cache.L2 << std::endl;
  std::cout << "  L3 = : " << cache.L3 << std::endl;
  std::cout << "Cache line size : " << std::endl;
  std::cout << "  l1 = : " << cache.l1 << std::endl;
  std::cout << "  l2 = : " << cache.l2 << std::endl;
  std::cout << "  l3 = : " << cache.l3 << std::endl;
  std::cout << "Cache coherency line size : " << nt2::config::get_cache_coherency_line_size(cache) << std::endl;
  std::cout << "===============================" << std::endl;

  for(int i = 0; i < 9; ++i)
    {
      if (nt2::config::has_vectorial_extension(ext[i]))
        {
          std::cout << ext[i] << " Found" << std::endl;
        }
      else
        {
          std::cout << ext[i] << " Not Found" << std::endl;
        }
    }

}
