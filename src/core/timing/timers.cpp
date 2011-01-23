/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#include <iostream>
#include <nt2/core/timing/tic.hpp>
#include <nt2/core/timing/ctic.hpp>

namespace nt2 { namespace details
{
  void cycle_based_timer::Print(const cycles_t& val)
  {
    std::cout << "Elapsed time is " << val << " CPU cycle(s).\n";
  }

  void second_based_timer::Print(const double& val)
  {
    std::cout << "Elapsed time is " << val << " s.\n";
  }
} }
