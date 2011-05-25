##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

# Search for HWLOC install

# Find HWLOC include
if(NOT HWLOC_INCLUDE_ROOT)
  find_path ( HWLOC_INCLUDE_ROOT hwloc
    PATHS
    /usr/local/include /usr/include
    ENV HWLOC_INCLUDE_ROOT
    )
  if(NOT HWLOC_INCLUDE_ROOT)
    message("Could not find HWLOC include path, bad install?")
  else()
    message("Found HWLOC include root ${HWLOC_INCLUDE_ROOT}")
  endif()
endif()

# Find HWLOC library
if(NOT HWLOC_LIBRARY_ROOT)
  find_path ( HWLOC_LIBRARY_ROOT lib
    PATHS
    /usr/local/ /usr/
    ENV HWLOC_LIBRARY_ROOT
    )
  if(NOT HWLOC_LIBRARY_ROOT)
    message("Could not find HWLOC library path, bad install?")
  else()
    message("Found HWLOC library root ${HWLOC_LIBRARY_ROOT}")
  endif()
endif()

if(NOT HWLOC_LIBRARY_DIR)
  find_library(HWLOC_LIBRARY_DIR hwloc
    PATHS HWLOC_LIBRARY_ROOT
    )
  if(NOT HWLOC_LIBRARY_DIR)
    message("Could not find HWLOC library, bad install?")
  else()
    message("Found HWLOC library ${HWLOC_LIBRARY_DIR}")
  endif()
endif()
