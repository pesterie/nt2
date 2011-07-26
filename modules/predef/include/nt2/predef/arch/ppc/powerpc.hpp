/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#if !defined(NT2_ARCH_PPC_POWERPC_HPP_INCLUDED) &&  \
    (defined(__powerpc)    || defined(__powerpc__)   \
    ||  defined(__POWERPC__)  || defined(__ppc__)   \
    ||  defined(_M_PPC)       || defined(_ARCH_PPC)) 
#define NT2_ARCH_PPC_POWERPC_HPP_INCLUDED

#if !defined(NT2_ARCH) || defined(DOXYGEN_ONLY)

    #define NT2_ARCH_POWERPC
    #define NT2_ARCH "Power PC"
    #define NT2_ARCH_ALIGNMENT 16
    #define NT2_INTEGER_REGISTERS 32
    #define NT2_INTEGER_REGISTERS_WIDTH 32
    #define NT2_FLOAT_REGISTERS 32
    #define NT2_FLOAT_REGISTERS_WIDTH 64

#endif
#endif
