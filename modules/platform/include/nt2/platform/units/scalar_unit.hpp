/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 sCNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_PLATFORM_UNITS_SCALAR_UNIT_HPP
#define NT2_PLATFORM_UNITS_SCALAR_UNIT_HPP

#include <nt2/predef/arch.hpp>
#include <boost/mpl/int.hpp>

namespace nt2 { namespace platform {

  struct scalar_unit
  {
    typedef boost::mpl::int_<NT2_INTEGER_REGISTERS>       integer_registers_;
    typedef boost::mpl::int_<NT2_INTEGER_REGISTERS_WIDTH> integer_registers_width_;
    typedef boost::mpl::int_<NT2_FLOAT_REGISTERS>         float_registers_;
    typedef boost::mpl::int_<NT2_FLOAT_REGISTERS_WIDTH>   float_registers_width_;

    inline int integer_registers(void) { return integer_registers_(); }
    inline int float_registers(void)   { return float_registers_(); }
    inline int integer_registers_width(void) { return integer_registers_width_(); }
    inline int float_registers_width(void)  { return float_registers_width_(); }
  };

} }

#endif /* NT2_PLATFORM_UNITS_SCALAR_UNIT_HPP */
