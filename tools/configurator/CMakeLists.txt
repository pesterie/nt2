################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
cmake_minimum_required(VERSION 2.8)

project(configurator)

set(CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/cmake/
    ${PROJECT_SOURCE_DIR}/../../cmake/
   )

find_package(NT2 COMPONENTS sdk platform REQUIRED)

if(NOT NT2_FOUND)
  message(FATAL_ERROR "Can not find NT² ! Dependence not met.")
else()

  include(nt2.gpu)
  include(nt2.threading)

  set(NT2_UNITS_HPP_GENERATE_PATH ${NT2_PLATFORM_INCLUDE_DIR}/nt2/platform/)
  file(MAKE_DIRECTORY ${NT2_UNITS_HPP_GENERATE_PATH}/units/)  
  set(NT2_UNITS_GENERATE_PATH ${NT2_UNITS_HPP_GENERATE_PATH}/units/)

  set(Boost_USE_STATIC_LIBS ON)
  find_package(Boost COMPONENTS program_options REQUIRED)

  configure_file(${PROJECT_SOURCE_DIR}/cmake/infos.hpp.cmake 
    ${PROJECT_BINARY_DIR}/include/infos.hpp
    )

  set(CONFIGURATOR_INCLUDES  ${CONFIGURATOR_INCLUDES} ${PROJECT_SOURCE_DIR}/include/ ${PROJECT_BINARY_DIR}/include/)
  set(CONFIGURATOR_LIBRARIES ${NT2_LIBRARIES})
 
  if(Boost_PROGRAM_OPTIONS_LIBRARY)
    set(CONFIGURATOR_LIBRARIES ${CONFIGURATOR_LIBRARIES} ${Boost_PROGRAM_OPTIONS_LIBRARY})
  endif()
 

  file( GLOB_RECURSE source_configurator_files
        ${PROJECT_SOURCE_DIR}/src/*
      )

  include_directories(${CONFIGURATOR_INCLUDES})
  
  add_executable(configure EXCLUDE_FROM_ALL ${source_configurator_files} )
  
  set_property(TARGET configure PROPERTY 
    RUNTIME_OUTPUT_DIRECTORY ${NT2_BUILD_DIR}
    )
  
  set_property(TARGET configure PROPERTY 
    OUTPUT_NAME "configure.run" 
    )
  
  target_link_libraries(configure ${CONFIGURATOR_LIBRARIES})
    
endif()