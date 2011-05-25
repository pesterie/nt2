##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################
nt2_module_source_setup(config)
nt2_module_configure_toolbox(config 0)

include(FindHWLOC)

set(CONFIG_SOURCES
    main.cpp)

INCLUDE_DIRECTORIES( 
  "${PROJECT_SOURCE_DIR}/include/"
  "${HWLOC_INCLUDE_ROOT}"
  )

add_executable(configure EXCLUDE_FROM_ALL ${CONFIG_SOURCES} )
set_property(TARGET configure PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries(configure ${HWLOC_LIBRARY_DIR})
