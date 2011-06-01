//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_ERROR_WARNING_HPP_INCLUDED
#define NT2_SDK_ERROR_WARNING_HPP_INCLUDED

/*!
 * \file
 * \brief Defines macros to output custom warning messages at compile time
 */

#include <boost/config.hpp>
#include <boost/preprocessor/stringize.hpp>

//==============================================================================
// Activate only in VERBOSE MODE
//==============================================================================
#if defined(NT2_VERBOSE)
#if defined(BOOST_MSVC)
//==============================================================================
// #pragma message on MSVC is very light so we add some info
//==============================================================================
#define NT2_WARNING_LOCATION __FILE__ "(" BOOST_PP_STRINGIZE(__LINE__) ") :"
#define NT2_WARN(exp) ( NT2_WARNING_LOCATION "[NT2 WARNING] -- "  BOOST_PP_STRINGIZE(exp) )
#define NT2_WARNING(X) __pragma( message NT2_WARN(X) )

#elif defined(__GNUC__)
//==============================================================================
// #pragma message on g++ just need a call to _Pragma
//==============================================================================
#define NT2_WARN(exp) "[NT2 WARNING] -- " #exp
#define NT2_WARNING(X) _Pragma( BOOST_PP_STRINGIZE(message NT2_WARN(X)) )
#endif
#else
//==============================================================================
/*!
 * \ingroup error
 * Emits a custom warning message at compile by displaying \c X in a file/line
 * localized message.
 *
 * \param MESSAGE Custom warning message
 *
 * \usage
 *
 * \include ../local.hpp
 */
//==============================================================================
#define NT2_WARNING(MESSAGE)
#endif

#endif
