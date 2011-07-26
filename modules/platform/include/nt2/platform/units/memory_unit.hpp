/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 sCNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_PLATFORM_UNITS_MEMORY_UNIT_HPP
#define NT2_PLATFORM_UNITS_MEMORY_UNIT_HPP

#include <nt2/predef/arch.hpp>
#include <nt2/sdk/config/cache.hpp>
#include <boost/mpl/int.hpp>

namespace nt2 { namespace platform {

  struct memory_unit
  {

    memory_unit() 
    {
      int rs = cache_infos(caches);
    }

    typedef boost::mpl::int_<NT2_ARCH_ALIGNMENT> nt2_arch_alignement_;

    int l1_line_size(void) { return caches.l1; }
    int l2_line_size(void) { return caches.l2; }
    int l3_line_size(void) { return caches.l3; }
    int l1_cache_size(void) { return caches.L1; }
    int l2_cache_size(void) { return caches.L2; }
    int l3_cache_size(void) { return caches.L3; }

  private:
    nt2::config::cache_report caches;
  };

} }

#endif /* NT2_PLATFORM_UNITS_MEMORY_UNIT_HPP */
