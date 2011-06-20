/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONFIG_CONFIGURATOR_INFOS_HPP_INCLUDED
#define NT2_SDK_CONFIG_CONFIGURATOR_INFOS_HPP_INCLUDED

#cmakedefine NT2_CONCEPT_GENERATE_PATH "${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/generate/"
#cmakedefine NT2_CONCEPT_DEFAULT_PATH "${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/default/"

#cmakedefine NT2_HAS_CUDA
#cmakedefine NT2_HAS_OCL
#cmakedefine NT2_HAS_OMP
#cmakedefine NT2_HAS_PTH
#cmakedefine NT2_HAS_TBB
#cmakedefine NT2_HAS_MPI
#cmakedefine NT2_HAS_PLX
#cmakedefine NT2_HAS_HWL

#endif