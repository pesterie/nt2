/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_TIMING_TIC_HPP_INCLUDED
#define NT2_CORE_TIMING_TIC_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <nt2/core/timing/timer.hpp>
#include <nt2/core/timing/now.hpp>

namespace nt2 { namespace details
{
  struct second_based_timer
  {
    static inline double  Time() { return details::now(); }

    static inline void Print(const double& val)
    {
       std::cout << "Elapsed time is " << val << " s.\n";
    }
  };

  counter<double,second_based_timer> const sec_timer = {};
} }

namespace nt2 { namespace time
{
  inline void tic() { details::sec_timer.tic(); }

  inline double  toc( bool display = true)
  {
    return details::sec_timer.toc(display);
  }
} }

namespace nt2
{
  // Convenience namespace injection from time:: into nt2::
  using time::tic;
  using time::toc;
}

#endif
