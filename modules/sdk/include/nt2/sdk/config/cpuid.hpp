/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_CPUID_HPP_INCLUDED
#define NT2_SDK_CONFIG_CPUID_HPP_INCLUDED

#define INTEL "GenuineIntel"
#define AMD   "AuthenticAMD"

namespace nt2{ namespace config{

#if defined(__GNUC__)

void __cpuid( int CPUInfo[4],int InfoType);
void __cpuidex(int CPUInfo[4],int InfoType,int ECXValue);

enum { eax,ebx,ecx,edx };

#elif defined(_MSC_VER)
#include <intrin.h>
#endif

bool processor_vendor(const int abcd[4], const char* vendor);

} }

#endif /* NT2_SDK_CONFIG_CPUID_HPP_INCLUDED */
