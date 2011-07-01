################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

################################################################################
# Find CUDA and set proper flags for nt2
################################################################################
include(FindCUDA)
IF(CUDA_FOUND)
SET(NT2_HAS_CUDA_SUPPORT 1)
ENDIF(CUDA_FOUND)

################################################################################
# Find OpenCL and set proper flags for nt2
################################################################################
# TODO : Write OpenCL find
IF(OCL_FOUND)
SET(NT2_HAS_OPENCL_SUPPORT 1)
ENDIF(OCL_FOUND)
