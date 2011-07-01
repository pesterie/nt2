################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
cmake_minimum_required(VERSION 2.6)

project(configurator)

set(CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/cmake/ 
    ${PROJECT_BINARY_DIR}/cmake/
   )

include(nt2.configurator)
include(nt2.hwloc)
include(nt2.gpu)
include(nt2.threading)
include(nt2.mpi)

include_directories(${NT2_CONFIGURATOR_INCLUDE_DIR})

find_library(BOOST_PROGRAM_OPT_STATIC libboost_program_options.a  ${NT2_CONFIGURATOR_LYBRARY_DIR}) 
find_library(BOOST_PROGRAM_OPT_SHARED libboost_program_options.so ${NT2_CONFIGURATOR_LYBRARY_DIR}) 

if(BOOST_PROGRAM_OPT_STATIC)
  set(BOOST_PROGRAM_OPT ${BOOST_PROGRAM_OPT_STATIC})
elseif(BOOST_PROGRAM_OPT_SHARED)
  set(BOOST_PROGRAM_OPT ${BOOST_PROGRAM_OPT_SHARED})
else()
  message(STATUS "Boost Program Options library can not be found.")
endif()

# This file does not need to be install.
configure_file(${PROJECT_SOURCE_DIR}/cmake/infos.hpp.cmake 
               ${NT2_BUILD_DIR}/include/nt2/sdk/config/infos.hpp
              )

file( GLOB_RECURSE source_configurator_files
      ${PROJECT_SOURCE_DIR}/*
    )

add_executable(configure EXCLUDE_FROM_ALL ${source_configurator_files} )

set_property(TARGET configure PROPERTY 
             RUNTIME_OUTPUT_DIRECTORY ${NT2_BUILD_DIR}
            )
set_property(TARGET configure PROPERTY 
             OUTPUT_NAME "configure.run" 
             )

target_link_libraries(configure ${BOOST_PROGRAM_OPT})