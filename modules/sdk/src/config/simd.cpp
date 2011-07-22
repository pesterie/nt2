/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 *******************************************************************************/
#include <nt2/sdk/config/simd.hpp>

namespace nt2{ namespace config {

int has_vectorial_extension(std::string const& target)
{
  int regs[4];

  __cpuid(regs,0x00000000);

  if(processor_vendor(regs, INTEL))
  {
    matcher options_intel[9] =
      {
          {0x00000001,edx,25} // SSE
        , {0x00000001,edx,26} // SSE2
        , {0x00000001,ecx,0} // SSE3
        , {0x00000001,ecx,9} // SSSE3
        , {0x00000001,ecx,19} // SSE4.1
        , {0x00000001,ecx,20} // SSE4.2
        , {0x00000001,ecx,28} // AVX
        , {0x80000001,ecx,11} // XOP
        , {0x80000001,ecx,16} // FMA
      };
    
    matcher m;
    
    if(target == "sse"    )      m = options_intel[0];
    else if(target == "sse2"   ) m = options_intel[1];
    else if(target == "sse3"   ) m = options_intel[2];
    else if(target == "ssse3"  ) m = options_intel[3];
    else if(target == "sse4.1" ) m = options_intel[4];
    else if(target == "sse4.2" ) m = options_intel[5];
    else if(target == "avx"    ) m = options_intel[6];
    else if(target == "xop"    ) m = options_intel[7];
    else if(target == "fma4"   ) m = options_intel[8];
    
    __cpuid(regs,m.function);
    return utils::has_bit_set(regs[m.reg],m.bit);
  }
  else if(processor_vendor(regs, AMD))
  {
     matcher options_amd[10] =
      {
          {0x00000001,edx,25} // SSE
        , {0x00000001,edx,26} // SSE2
        , {0x00000001,ecx,0} // SSE3
        , {0x00000001,ecx,9} // SSSE3
        , {0x00000001,ecx,19} // SSE4.1
        , {0x00000001,ecx,20} // SSE4.2
        , {0x00000001,ecx,28} // AVX
        , {0x80000001,ecx,11} // XOP
        , {0x80000001,ecx,12} // FMA
      };
    
    matcher m;

    if(target == "sse"    )      m = options_amd[0];
    else if(target == "sse2"   ) m = options_amd[1];
    else if(target == "sse3"   ) m = options_amd[2];
    else if(target == "ssse3"  ) m = options_amd[3];
    else if(target == "sse4.1" ) m = options_amd[4];
    else if(target == "sse4.2" ) m = options_amd[5];
    else if(target == "avx"    ) m = options_amd[6];
    else if(target == "xop"    ) m = options_amd[7];
    else if(target == "fma4"   ) m = options_amd[8];

    __cpuid(regs,m.function);
    return utils::has_bit_set(regs[m.reg],m.bit);
  } 
}


}  }
