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
#nt2_module_configure_toolbox(config 0)

################################################################################
# Generate bootstrap.hpp
################################################################################
nt2_module_configure_file(bootstrap.hpp.cmake
                          nt2/sdk/config/bootstrap.hpp
                         )

file( GLOB_RECURSE source_config_files
      ${NT2_CONFIG_ROOT}/src/*
    )

SET(SOURCE_FILES ${source_config_files} CACHE INTERNAL "")



if(NT2_CUSTOM_CONFIGURATION)

include(FindHWLOC)
find_library(BOOST_PROGRAM_OPT_STATIC libboost_program_options.a  ${Boost_LIBRARIES}) 
find_library(BOOST_PROGRAM_OPT_SHARED libboost_program_options.so ${Boost_LIBRARIES}) 
if(BOOST_PROGRAM_OPT_STATIC)
  set(BOOST_PROGRAM_OPT ${BOOST_PROGRAM_OPT_STATIC})
elseif(BOOST_PROGRAM_OPT_SHARED)
  set(BOOST_PROGRAM_OPT ${BOOST_PROGRAM_OPT_SHARED})
else()
  message("Boost Program Options library can not be")
endif()

file( GLOB_RECURSE source_configurator_files
      ${NT2_CONFIG_ROOT}/src/configurator/*
    )

add_executable(configure EXCLUDE_FROM_ALL ${source_configurator_files} )
set_property(TARGET configure PROPERTY 
             RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
             )
set_property(TARGET configure PROPERTY 
             OUTPUT_NAME "configure.run" 
             )
target_link_libraries(configure ${BOOST_PROGRAM_OPT})

endif()