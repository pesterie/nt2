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
#include <units/units.hpp>
#include <infos.hpp>      
#include <nt2/sdk/config/gpu.hpp>      
#include <boost/program_options.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <string>
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
      ("runtime", "Test your hardware specifications and generate the Architecture Concept")
      ("manual" , "Manuel genration of the Architecture Concept")
      ("help"       , "Start help")
      ;
    
    po::variables_map vm;        
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);  

    if(vm.count("runtime")) 
    {
      // Generating Scalar Unit 
      cf::utils::generate_scalar_unit(NT2_UNITS_GENERATE_PATH, "scalar_unit");

      // Generating SIMD Unit 
      cf::utils::generate_simd_unit(NT2_UNITS_GENERATE_PATH, "simd_unit");

      //Generating Memory Unit
      cf::utils::generate_memory_hierarchy(NT2_UNITS_GENERATE_PATH, "memory_unit");

      //Generating Core Unit
      cf::utils::generate_core_unit(NT2_UNITS_GENERATE_PATH, "core_unit");

      // std::cout << "Detecting GPU devices specifications...\n";
      // nt2::config::gpu_report gpu;
      // int result = nt2::config::get_gpu_devices_properties(gpu);
      // if(gpu.size() != 0) 
      // {
      //   for(int idx = 0; idx < gpu.size(); ++idx)
      //   {
          
      //   }
      // }
      // else std::cerr << "No GPU Devices detected!\n";
     
    }
    else if(vm.count("manual"))
    {
      // TODO
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
