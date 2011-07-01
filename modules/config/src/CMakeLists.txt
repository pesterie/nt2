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

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/configurator)
set(CONFIGURATOR_BUILD_DIR ${PROJECT_BINARY_DIR}/build_configurator)

# This file does not need to be install.
set(NT2_CONFIGURATOR_CMAKE_FILE ${CONFIGURATOR_BUILD_DIR}/cmake/nt2.configurator.cmake)
set(NT2_CONCEPT_GENERATE_PATH_ ${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/generate/)
set(NT2_CONCEPT_DEFAULT_PATH_ ${PROJECT_SOURCE_DIR}/modules/arch/include/nt2/arch/concepts/default/)

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

set(FORWARD_INCLUDE ${NT2_CONFIG_DEPENDENCIES_INCLUDE_DIR} ${NT2_CONFIG_INCLUDE_DIR})
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
     "set(NT2_CONCEPT_GENERATE_PATH ${NT2_CONCEPT_GENERATE_PATH_})\n"
    )

file(APPEND ${NT2_CONFIGURATOR_CMAKE_FILE}
     "set(NT2_CONCEPT_DEFAULT_PATH ${NT2_CONCEPT_DEFAULT_PATH_})\n"
    )

################################################################################
# Configurator for fine grain configuration 
################################################################################

message(STATUS "Generating Makefile system for Configurator...")

execute_process(COMMAND ${CMAKE_COMMAND} ${NT2_CONFIG_ROOT}/src/configurator/
                WORKING_DIRECTORY ${CONFIGURATOR_BUILD_DIR}
                RESULT_VARIABLE CMAKE_RESULT
               )

message(STATUS "Compiling Configurator...")

execute_process(COMMAND ${CMAKE_MAKE_PROGRAM} configure
                WORKING_DIRECTORY ${CONFIGURATOR_BUILD_DIR}
                RESULT_VARIABLE BUILD_RESULT
               )

