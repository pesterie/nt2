################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
IF (WIN32)

# TODO

ELSE (WIN32)

set(OPENCL_PATH_TO_SEARCH 
    /usr/include/CL/
    /usr/local/include/CL/
    /usr/share/CL/
    /usr/local/cuda/include/CL/
    /opt/
    /etc/
    )
  
  FIND_PATH(OPENCL_INCLUDE_DIR 
            NAMES 
              cl.h
	    PATHS
	      ${OPENCL_PATH_TO_SEARCH}
	    ) 

  FIND_LIBRARY(OPENCL_LIBRARIES OpenCL 
               ENV LD_LIBRARY_PATH
	       )
  
ENDIF (WIN32)

SET( OPENCL_FOUND false )
IF(OPENCL_LIBRARIES )
  SET( OPENCL_FOUND true )
ENDIF(OPENCL_LIBRARIES)
