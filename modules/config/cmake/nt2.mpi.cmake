################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

################################################################################
# Find abotu MPI
################################################################################

include(FindMPI)

IF(MPI_FOUND)
SET(NT2_HAS_MPI_SUPPORT 1)
SET(CONFIGURATOR_LIBRARIES ${CONFIGURATOR_LIBRARIES} ${MPI_LIBRARIES})
SET(CONFIGURATOR_INCLUDES ${CONFIGURATOR_INCLUDES} ${MPI_INCLUDE_PATH})
ENDIF(MPI_FOUND)

