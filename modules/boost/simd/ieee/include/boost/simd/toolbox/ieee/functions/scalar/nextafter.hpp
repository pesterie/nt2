//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SCALAR_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SCALAR_NEXTAFTER_HPP_INCLUDED

#include <boost/simd/include/functions/sign.hpp>
#include <boost/simd/include/constants/one.hpp>

#include <boost/simd/toolbox/ieee/details/math.hpp>
#include <boost/math/special_functions/next.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/minf.hpp>

// workaround for boost.math bug #5823
namespace boost { namespace simd { namespace details
{
  template<class T>
  T nextafter(T a0, T a1)
  {
    if(a0 > a1 && a0 == Inf<T>())
      return Valmax<T>();
    if(a0 < a1 && a0 == Minf<T>())
      return Valmin<T>();

    using namespace boost::math::policies;
    typedef policy<
      domain_error<errno_on_error>,
      pole_error<errno_on_error>,
      overflow_error<errno_on_error>,
      evaluation_error<errno_on_error>,
      rounding_error<errno_on_error>
    > c_policy;

    return boost::math::nextafter(a0, a1, c_policy());
  }
} } }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::nextafter_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return a0+sign(a1-a0);
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::nextafter_, tag::cpu_
                            , (A0)
                            , (scalar_< double_<A0> >)(scalar_< double_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
    #ifdef BOOST_SIMD_TOOLBOX_IEEE_HAS_NEXTAFTER
      return ::nextafter(a0, a1);
    #elif defined(BOOST_SIMD_TOOLBOX_IEEE_HAS__NEXTAFTER)
      return ::_nextafter(a0, a1);
    #else
      return details::nextafter(a0, a1);
    #endif
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::nextafter_, tag::cpu_
                            , (A0)
                            , (scalar_< float_<A0> >)(scalar_< float_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
    #ifdef BOOST_SIMD_TOOLBOX_IEEE_HAS_NEXTAFTERF
      return ::nextafterf(a0, a1);
    #elif defined(BOOST_SIMD_TOOLBOX_IEEE_HAS__NEXTAFTERF)
      return ::_nextafterf(a0, a1);
    #else
      return details::nextafter(a0, a1);
    #endif
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::nextafter_, tag::cpu_
                            , (A0)
                            , (scalar_< unsigned_<A0> >)(scalar_< unsigned_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return (a1 == a0) ? a0 : (a1 > a0) ? a0+One<A0>() : a0-One<A0>();
    }
  };
} } }


#endif
