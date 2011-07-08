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

include_directories(${NT2_CONFIGURATOR_INCLUDE_DIR})

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.46.0 COMPONENTS program_options REQUIRED)

if(Boost_PROGRAM_OPTIONS_LIBRARY)
set(LIBRARIES_TO_LINK ${Boost_PROGRAM_OPTIONS_LIBRARY})
endif()
 
if(NT2_CUDA_CONFIG)
  if(NT2_CUDA_LIB)
    set(LIBRARIES_TO_LINK ${LIBRARIES_TO_LINK} ${NT2_CUDA_LIB})
  else()
    message(SEND_ERROR "Can't find CUDA library !")
  endif()
elseif(NT2_OPENCL_CONFIG)
  if(NT2_OPENCL_LIB)
    set(LIBRARIES_TO_LINK ${LIBRARIES_TO_LINK} ${NT2_OPENCL_LIB})
  else()
    message(SEND_ERROR "Can't find CUDA library !")
  endif()
endif()


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

target_link_libraries(configure ${LIBRARIES_TO_LINK})