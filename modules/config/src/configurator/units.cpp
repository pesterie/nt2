//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/configurator/units.hpp>
#include <nt2/sdk/config/configurator/header.hpp>
#include <nt2/sdk/config/configurator/simd.hpp>
#include <boost/array.hpp>
#include <nt2/arch/setup/default/arch.hpp>

namespace nt2 { namespace config { namespace utils {

  void generate_scalar_unit(std::string const& path, std::string const& name)
  {
    header scalar_unit(path, name);
#if defined(NT2_HAS_UNKOWN)
    scalar_unit.add_define(HAS_UNKNOW_ARCH);
#elif defined(NT2_ARCH_IA64)
    scalar_unit.add_define(IA64_SCALAR_UNIT);
    scalar_unit.add_macro(IA64_GP_REG, 128);
    scalar_unit.add_macro(IA64_GP_REG_WIDTH, 64);
    scalar_unit.add_macro(IA64_FP_REG, 128);
    scalar_unit.add_macro(IA64_FP_REG_WIDTH, 82);
#elif defined(NT2_ARCH_POWERPC)
    scalar_unit.add_define(POWERPC_SCALAR_UNIT);
    scalar_unit.add_macro(POWERPC_GP_REG, 32);
    //scalar_unit.add_macro(POWERPC_GP_REG_WIDTH, 64);
    scalar_unit.add_macro(POWERPC_FP_REG, 32);
    //scalar_unit.add_macro(POWERPC_FP_REG_WIDTH, 64);
#elif defined(NT2_ARCH_X86_64)
    scalar_unit.add_define(X86_64_SCALAR_UNIT);
    scalar_unit.add_macro(X86_64_GP_REG, 14);
    scalar_unit.add_macro(X86_64_GP_REG_WIDTH, 64);
    scalar_unit.add_macro(X86_64_FP_REG, 8);
    scalar_unit.add_macro(X86_64_FP_REG_WIDTH, 32);
#elif defined(NT2_ARCH_X86)
    scalar_unit.add_define(X86_SCALAR_UNIT);
    scalar_unit.add_macro(X86_GP_REG, 6);
    scalar_unit.add_macro(X86_GP_REG_WIDTH, 32);
    scalar_unit.add_macro(X86_FP_REG, 8);
    scalar_unit.add_macro(X86_FP_REG_WIDTH, 32);
#endif

    scalar_unit.generate_class();
  }


  void generate_simd_unit(std::string const& path, std::string const& name)
  {
    header simd_unit(path, name);

#if defined(NT2_HAS_VMX_SUPPORT)
    //TODO : Get back VMX detection from script !
#elif defined(NT2_HAS_UNKOWN)
      simd_unit.add_define(HAS_UNKNOW_ARCH);
#else 
    boost::array<const std::string,9> ext = {{"sse","sse2","sse3","ssse3","sse4.1","sse4.2","avx","xop","fma4"}};
    boost::array<const std::string,9> EXT = {{"HAS_SSE_SUPPORT","HAS_SSE2_SUPPORT","HAS_SSE3_SUPPORT",
                                              "HAS_SSSE3_SUPPORT","HAS_SSE4_1_SUPPORT","HAS_SSE4_2_SUPPORT",
                                              "HAS_AVX_SUPPORT","HAS_XOP_SUPPORT","HAS_FMA4_SUPPORT"}};

    // Detecting SIMD extensions
    std::cout << "Testing SIMD extensions available...\n";
    int nb_fail = 0;
    bool avx_found;

    for(int i = 0; i < 9; ++i)
      {
        if (nt2::config::has_vectorial_extension(ext[i]))
          {
            std::cout << "-- " << ext[i] << " -> Success\n";
            if(ext[i] == "avx") avx_found = true;
            simd_unit.add_define(EXT[i]);
          }
        else{ std::cerr << "-- " << ext[i] << " -> Fail\n"; ++nb_fail; }
      }
    
    if(nb_fail > 8)
    {
#if   defined(NT2_ARCH_IA64)
      simd_unit.add_define(IA64_SIMD_UNIT);
      simd_unit.add_macro(IA64_SIMD_REG, 16);
      simd_unit.add_macro(IA64_SIMD_REG_WIDTH, 128);
#elif defined(NT2_ARCH_X86_64)
      simd_unit.add_define(X86_64_SIMD_UNIT);
      simd_unit.add_macro(X86_64_SIMD_REG, 16);
      simd_unit.add_macro(X86_64_SIMD_REG_WIDTH, 128);
      if(avx_found == true) simd_unit.add_macro(X86_64_SIMD_REG_WIDTH, 128);
#elif defined(NT2_ARCH_X86)
      simd_unit.add_define(X86_SIMD_UNIT);
      simd_unit.add_macro(X86_SIMD_REG, 8);
      simd_unit.add_macro(X86_SIMD_REG_WIDTH, 128);
#endif

#endif
      
      simd_unit.generate_class();

    }
  }
      
} } }

