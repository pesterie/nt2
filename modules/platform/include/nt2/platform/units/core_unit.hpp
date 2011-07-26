/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 sCNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_PLATFORM_UNITS_CORE_UNIT_HPP
#define NT2_PLATFORM_UNITS_CORE_UNIT_HPP

namespace nt2 { namespace platform {

  template<class ScalarUnit, class SimdUnit, class MemoryUnit>
  struct core_unit
  {
    typedef ScalarUnit scalar_unit;
    typedef SimdUnit   simd_unit;
    typedef MemoryUnit memory_unit;

    scalar_unit scalar;
    simd_unit   simd;
    memory_unit memory;
  };

} }


#endif /* NT2_PLATFORM_UNITS_CORE_UNIT_HPP */
