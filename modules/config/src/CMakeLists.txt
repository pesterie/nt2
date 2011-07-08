################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(NT2Module)
nt2_module_source_setup(config)

file( GLOB_RECURSE source_config_files
      ${NT2_CONFIG_ROOT}/src/*
    )

SET(SOURCE_FILES ${source_config_files} CACHE INTERNAL "")


################################################################################
# Generate nt2.configurator.cmake for configurator
################################################################################

include(nt2.hwloc)
include(nt2.gpu)
include(nt2.threading)
include(nt2.mpi)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/build_configurator)
set(CONFIGURATOR_BUILD_DIR ${PROJECT_BINARY_DIR}/build_configurator)

# This file does not need to be install.
set(NT2_CONFIGURATOR_CMAKE_FILE ${CONFIGURATOR_BUILD_DIR}/cmake/nt2.configurator.cmake)
set(NT2_CONCEPT_GENERATE_PATH ${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/generate/)
set(NT2_CONCEPT_DEFAULT_PATH ${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/default/)

file(WRITE ${NT2_CONFIGURATOR_CMAKE_FILE}
"################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################\n"
    )

set(FORWARD_INCLUDE ${NT2_CONFIG_DEPENDENCIES_INCLUDE_DIR} ${NT2_CONFIG_INCLUDE_DIR} ${CONFIGURATOR_INCLUDES})
string(REPLACE ";" " " FORWARD_INCLUDE_TO_WRITE "${FORWARD_INCLUDE}")

file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONFIGURATOR_INCLUDE_DIR ${FORWARD_INCLUDE_TO_WRITE})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONFIGURATOR_LYBRARY_DIR ${NT2_CONFIG_DEPENDENCIES_LIBRARY_DIR})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONFIGURATOR_BUILD_DIR ${CONFIGURATOR_BUILD_DIR})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_BUILD_DIR ${PROJECT_BINARY_DIR})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONCEPT_GENERATE_PATH ${NT2_CONCEPT_GENERATE_PATH})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONCEPT_DEFAULT_PATH ${NT2_CONCEPT_DEFAULT_PATH})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(MPI_FOUND ${MPI_FOUND})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_MPI_LIB ${MPI_LIBRARY})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(CUDA_FOUND ${CUDA_FOUND})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CUDA_LIB ${CUDA_LIBRARIES})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(OPENCL_FOUND ${OPENCL_FOUND})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_OPENCL_LIB ${OPENCL_LIBRARIES})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(OPENMP_FOUND ${OPENMP_FOUND})\n"
    )
file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(Threads_FOUND ${Threads_FOUND})\n"
    )

# file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
#      "set(TBB_FOUND ${TBB_FOUND})"
#     )

file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(HWLOC_FOUND ${HWLOC_FOUND})\n"
    )

# file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
#      "set(PLX_FOUND ${PLX_FOUND})"
#     )


# This file does not need to be install.
configure_file(${NT2_CONFIG_ROOT}/cmake/infos.hpp.cmake 
               ${PROJECT_BINARY_DIR}/include/nt2/sdk/config/infos.hpp
              )

################################################################################
# Configurator for fine grain configuration 
################################################################################

message(STATUS "Generating Makefile system for Configurator...")

if(CUDA_FOUND)
execute_process(COMMAND ${CMAKE_COMMAND} -DNT2_CUDA_CONFIG=true ${NT2_CONFIG_ROOT}/src/configurator/
                WORKING_DIRECTORY ${CONFIGURATOR_BUILD_DIR}
                RESULT_VARIABLE CMAKE_RESULT
               )
elseif(OPENCL_FOUND)
execute_process(COMMAND ${CMAKE_COMMAND} -DNT2_OPENCL_CONFIG=true ${NT2_CONFIG_ROOT}/src/configurator/
                WORKING_DIRECTORY ${CONFIGURATOR_BUILD_DIR}
                RESULT_VARIABLE CMAKE_RESULT
               )
endif()

message(STATUS "Compiling Configurator...")

execute_process(COMMAND ${CMAKE_MAKE_PROGRAM} configure
                WORKING_DIRECTORY ${CONFIGURATOR_BUILD_DIR}
                RESULT_VARIABLE BUILD_RESULT
               )

