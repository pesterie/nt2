/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <nt2/sdk/config/cpuid.hpp>
#include <string>

namespace nt2 { namespace config{

#ifdef NT2_COMPILER_GNU_C
void __cpuid( int CPUInfo[4],int InfoType)
{
  __asm__ __volatile__
  (
    "cpuid":\
    "=a" (CPUInfo[eax]), "=b" (CPUInfo[ebx])
  , "=c" (CPUInfo[ecx]), "=d" (CPUInfo[edx])
  : "a" (InfoType)
  );
}

void __cpuidex(int CPUInfo[4],int InfoType,int ECXValue)
{
  __asm__ __volatile__
  (
    "cpuid":\
    "=a" (CPUInfo[eax]), "=b" (CPUInfo[ebx])
  , "=c" (CPUInfo[ecx]), "=d" (CPUInfo[edx])
  : "a" (InfoType), "c" (ECXValue)
  );
}

#elif defined(NT2_COMPILER_MSVC)
#include <intrin.h>
#endif


bool processor_vendor(const int abcd[4], const char* vendor)
{
  return (abcd[1] == ((int*)(vendor))[0] && abcd[2] == ((int*)(vendor))[2] && abcd[3] == ((int*)(vendor))[1]);
}

} }
