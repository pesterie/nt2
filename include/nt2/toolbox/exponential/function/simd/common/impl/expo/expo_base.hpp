//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_IMPL_EXPO_EXPO_BASE_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SIMD_COMMON_IMPL_EXPO_EXPO_BASE_HPP_INCLUDED
#include <nt2/include/functions/select.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0, class Tag,  class Speed_Tag > 
      struct exponential < A0, Tag, tag::simd_type, Speed_Tag>
      {
	typedef exp_reduction<A0,Tag>                        reduc_t;
	typedef exp_finalization<A0,Tag,Speed_Tag>        finalize_t; 
	// compute exp(ax)
	static inline A0 expa( A0 a0)
	{
	  A0 hi, lo, x; 
	  A0 k = reduc_t::reduce(a0, hi, lo, x);
	  A0 c = reduc_t::approx(x);
	  A0 ge = reduc_t::isgemaxlog(a0);
	  A0 le = reduc_t::isleminlog(a0); 
          return sel(ge, Inf<A0>(),
		     sel(le, Zero<A0>(),
			 finalize_t::finalize(a0, x, c, k, hi, lo)
			 )
		     ); 
	}
      }; 	
    }
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of expo_base.hpp
// /////////////////////////////////////////////////////////////////////////////
