//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <units/units.hpp>
#include <utils/header.hpp>
#include <nt2/predef/arch.hpp>
#include <nt2/sdk/config/simd.hpp>
#include <nt2/sdk/config/cache.hpp>
#include <nt2/sdk/config/core.hpp>
#include <boost/array.hpp>

namespace nt2 { namespace config { namespace utils {

  void generate_scalar_unit(std::string const& path, std::string const& name)
  {
    header scalar_unit(path, name);
#if defined(NT2_HAS_UNKOWN)
    scalar_unit.add_define("HAS_UNKNOW_SCALAR_UNIT");
#elif defined(NT2_ARCH)
    scalar_unit.add_define("NT2_SCALAR_UNIT");
    scalar_unit.add_include("nt2/predef/arch.hpp");
    scalar_unit.add_metafunction("integer_registers_", "NT2_INTEGER_REGISTERS");
    scalar_unit.add_metafunction("integer_registers_width_", "NT2_INTEGER_REGISTERS_WIDTH");
    scalar_unit.add_metafunction("float_registers_", "NT2_FLOAT_REGISTERS");
    scalar_unit.add_metafunction("float_registers_width_", "NT2_INTEGER_REGISTERS_WIDTH");
    scalar_unit.add_methode("integer_registers", "integer_registers_()");
    scalar_unit.add_methode("integer_registers_width", "integer_registers_width_()");
    scalar_unit.add_methode("float_registers", "float_registers_()");
    scalar_unit.add_methode("float_registers_width", "integer_registers_width_()");
#endif
    scalar_unit.generate_class();
  }


  void generate_simd_unit(std::string const& path, std::string const& name)
  {
    header simd_unit(path, name);
#if defined(NT2_HAS_UNKOWN)
    simd_unit.add_define("HAS_UNKNOW_SIMD_UNIT");
#elif defined(NT2_ARCH)
    simd_unit.add_define("NT2_SIMD_UNIT");
#if defined(NT2_SIMD_REGISTERS) 
    simd_unit.add_include("nt2/predef/arch.hpp");
    simd_unit.add_metafunction("simd_registers_", "NT2_SIMD_REGISTERS");
    simd_unit.add_methode("simd_registers", "simd_registers_()");
#endif
#endif  
    simd_unit.generate_class();
    
  }

  void generate_memory_hierarchy(std::string const& path, std::string const& name)
  {
    header memory_unit(path, name);
#if defined(NT2_HAS_UNKOWN)
    memory_unit.add_define("HAS_UNKNOW_MEMORY_UNIT");
#elif defined(NT2_ARCH)
    memory_unit.add_define("NT2_MEMORY_UNIT");
    memory_unit.add_include("nt2/predef/arch.hpp");
    // Getting cache specs
    nt2::config::cache_report cache;
    std::cout << "Detecting cache specifications...\n";
    if( nt2::config::cache_infos(cache) == 0)
      {
        if(cache.L1 > 0) 
          {
            memory_unit.add_macro("L1_CACHE_SIZE", cache.L1);
            memory_unit.add_metafunction("l1_cache_size_", "L1_CACHE_SIZE");
            memory_unit.add_methode("l1_cache_size", "l1_cache_size_()");
            std::cout << "-- L1 cache size : " << cache.L1 << " kB\n";
          }
        if(cache.L2 > 0) 
          {  
            memory_unit.add_macro("L2_CACHE_SIZE", cache.L2);
            memory_unit.add_metafunction("l2_cache_size_", "L2_CACHE_SIZE");
            memory_unit.add_methode("l2_cache_size", "l2_cache_size_()");
            std::cout << "-- L2 cache size : " << cache.L2 << " kB\n";
          }
        if(cache.L3 > 0) 
          {
            memory_unit.add_macro("L3_CACHE_SIZE", cache.L3);
            memory_unit.add_metafunction("l3_cache_size_", "L3_CACHE_SIZE");
            memory_unit.add_methode("l3_cache_size", "l3_cache_size_()");
            std::cout << "-- L3 cache size : " << cache.L3 << " kB\n";
          }
        if(cache.l1 > 0)
          {
            memory_unit.add_macro("L1_LINE_SIZE",  cache.l1);
            memory_unit.add_metafunction("l1_line_size_", "L1_LINE_SIZE");
            memory_unit.add_methode("l1_line_size", "l1_line_size_()");
            std::cout << "-- L1 cache line size : " << cache.l1 << " bytes\n";
          }
        if(cache.l2 > 0) 
          { 
            memory_unit.add_macro("L2_LINE_SIZE",  cache.l2);
            memory_unit.add_metafunction("l2_line_size_", "L2_LINE_SIZE");
            memory_unit.add_methode("l2_line_size", "l2_line_size_()");
            std::cout << "-- L2 cache line size : " << cache.l2 << " bytes\n";
          }
        if(cache.l3 > 0) 
          {  
            memory_unit.add_macro("L3_LINE_SIZE",  cache.l3);
            memory_unit.add_metafunction("l3_line_size_", "L3_LINE_SIZE");
            memory_unit.add_methode("l3_line_size", "l3_line_size_()");
            std::cout << "-- L3 cache line size : " << cache.l3 << " bytes\n";
          }
        
        int coh = nt2::config::cache_coherency_line_size(cache);
        if(coh > 0) 
          {
            memory_unit.add_macro("COHERENCY_LINE_SIZE", coh);
            memory_unit.add_metafunction("coherency_line_size_", "COHERENCY_LINE_SIZE");
            memory_unit.add_methode("coherency_line_size", "coherency_line_size_()");
          }
        else std::cout << "-- Getting cache specifications failed.";
      }

#endif 

    memory_unit.generate_class();

  }
    
  void generate_core_unit(std::string const& path, std::string const& name)
  {
    header core_unit(path, name);
    
    core_unit.add_include("nt2/platform/units/scalar_unit.hpp");
    core_unit.add_typedef("scalar_unit", "scalarUnit");
    core_unit.add_include("nt2/platform/units/simd_unit.hpp");
    core_unit.add_typedef("simd_unit", "simdUnit");
    core_unit.add_include("nt2/platform/units/memory_unit.hpp");
    core_unit.add_typedef("memory_unit", "memoryUnit");

    // Detecting Multicore capabilities
    std::cout << "Detecting Multithreading capabilities...\n";
    int nb_cores = nt2::config::nb_threads();
    if(nb_cores > 0) 
    {
      core_unit.add_macro("NB_CORES", nb_cores);
      core_unit.add_metafunction("nb_core_", "NB_CORE");
      core_unit.add_methode("nb_core", "nb_core_()");
      std::cout << "-- Total cores found (Logical and Physical) : " << nb_cores << "\n";
    }
    else std::cerr << "-- Not a multicore architecture (Core test failed).\n";
      
    int nb_logical_cores_per_unit = nt2::config::nb_logical_cores();
    if(nb_logical_cores_per_unit > 0) 
    {
      core_unit.add_macro("NB_LOGICAL_CORES_PER_UNIT", nb_logical_cores_per_unit);
      core_unit.add_metafunction("nb_logical_core_per_unit_", "NB_LOGICAL_CORES_PER_UNIT");
      core_unit.add_methode("nb_logical_core_per_unit", "nb_logical_core_per_unit_()");
      std::cout << "-- Logical cores per unit found : " << nb_logical_cores_per_unit << "\n";
    }
    else std::cerr << "-- Not a multicore architecture (Logical Core test failed).\n";

    int nb_physical_cores = nt2::config::nb_physical_cores();
    if(nb_physical_cores > 0) 
    {
      core_unit.add_macro("NB_PHYSICAL_CORES", nb_physical_cores);
      core_unit.add_metafunction("nb_physical_core_", "NB_PHYSICAL_CORE");
      core_unit.add_methode("nb_physical_core", "nb_physical_core_()");
      std::cout << "-- Physical cores found : " << nb_physical_cores << "\n";
    }
    else std::cerr << "-- Not a multicore architecture (Physical Core test failed).\n";

    core_unit.generate_class();
  }
      
} } }

