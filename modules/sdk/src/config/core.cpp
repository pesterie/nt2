/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <nt2/sdk/config/core.hpp>

namespace nt2 { namespace config {

bool is_multithreaded(void)
{
  int regs[4];
  if(processor_vendor(regs, INTEL) || processor_vendor(regs, AMD))
  {
    __cpuid(regs, 0x00000001);
    return utils::has_bit_set(regs[3], 28);
  }
  else //Intel by default
  {
    __cpuid(regs, 0x00000001);
    return utils::has_bit_set(regs[3], 28);
  }
}

int nb_threads(void)
{
  int regs[4];
  __cpuidex(regs, 0x0000000B, 0x00000000);
  return utils::get_range(regs[1], 0, 16);
}

int nb_physical_cores(void)
{
  int regs[4];
  __cpuid(regs, 0x00000000);
  if(processor_vendor(regs, INTEL)) { return (nb_logical_cores()/nb_threads()); }
  else if(processor_vendor(regs, AMD)) 
  {
    __cpuid(regs, 0x80000008);
    return (utils::get_byte(regs[2], 0) + 1);
  }
  else { return (nb_logical_cores()/nb_threads()); } //Intel by default
}

int nb_logical_cores(void)
{
  int regs[4];
  __cpuid(regs, 0x00000000);
  if(processor_vendor(regs, INTEL)) 
  {
    __cpuidex(regs, 0x0000000B, 0x00000001);
    return utils::get_range(regs[1], 0, 16);
  }
  else if(processor_vendor(regs, AMD)) 
  {
    __cpuid(regs, 0x00000001);
    return (utils::get_range(regs[1], 16, 24));
  }
  else //Intel by default
  {
    __cpuidex(regs, 0x0000000B, 0x00000001);
    return utils::get_range(regs[1], 0, 16);
  }
}

} }
