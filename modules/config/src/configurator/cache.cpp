/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 sCNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <nt2/sdk/config/configurator/cache.hpp>


namespace nt2 { namespace config {



////////////////////////////////////////////////////////////////////////////////
//Cache infos functions
////////////////////////////////////////////////////////////////////////////////

//Return the cache sizes according to the level 
int get_cache_infos(cache_report &cache)
{
  int regs[4];
  //int nb_call_cpuid;

  cache.L1 = cache.L2 = cache.L3 = 0;
  cache.l1 = cache.l2 = cache.l3 = 0;

  __cpuid(regs, 0x00000000);
  
  if(get_vendor(regs, INTEL))
  {
    //__cpuid(regs, 0x00000002);
    //nb_call_cpuid = utils::get_byte(regs[0], 0);
    return get_cache_sizes_intel(cache);
  }
  else if(get_vendor(regs, AMD))
  {
    return get_cache_sizes_amd(cache);
  }
  else return -1;
}

int get_cache_sizes_intel(cache_report &cache)
{
  int regs[4] = {0,0,0,0};
  int byte0, byte1, byte2, byte3;
  int cache_ecx = 0;
  int cache_eax = 0;

  do{
    __cpuidex(regs, 0x00000004, cache_ecx);
    cache_eax = regs[0] & 0x0000001F;
    if(cache_eax == 1 || cache_eax == 3)
      {
        int level      = (regs[0] & 0x000000E0) >> 5; 
        int ways       = (regs[1] & 0xFFC00000) >> 22; 
        int partitions = (regs[1] & 0x003FF000) >> 12; 
        int line_size  = (regs[1] & 0x00000FFF) >>  0; 
        int sets       = (regs[2]);                   
        int size       = (ways+1)*(partitions+1)*(line_size+1)*(sets+1);
        
        switch(level)
        {
        case 1  : cache.L1 = size/1024; cache.l1 = line_size+1; break; 
        case 2  : cache.L2 = size/1024; cache.l2 = line_size+1; break;
        case 3  : cache.L3 = size/1024; cache.l3 = line_size+1; break;
        default : break;
        }
      }
    cache_ecx++;
  }while(cache_eax != 0x00000000);

  return 0;
}

int get_cache_sizes_amd(cache_report &cache)
{
  int regs[4] = {0,0,0,0};
  __cpuidex(regs,0x80000005,0);
  cache.l1 = regs[2] & 0x000000FF;
  cache.L1 = regs[2] >> 24; 
  regs[0] = regs[1] = regs[2] = regs[3] = 0;
  __cpuidex(regs,0x80000006,0);
  cache.l2 = regs[2] & 0x000000FF;
  cache.L2 = (regs[2] >> 16); 
  cache.l3 = regs[3] & 0x000000FF;
  cache.L3 = ((regs[3] & 0xFFFC000) >> 18)*512; // D[31;18] = l3 cache size in 512KB
  return 0;
}

//Return the coherency line size
int get_cache_coherency_line_size(cache_report const& cache)
{
  return utils::lcm( cache.l3, utils::lcm(cache.l2, cache.l1) );
}

} }
