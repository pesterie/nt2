/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONSTANT_DETAILS_SIGNMASK_HPP_INCLUDED
#define NT2_SDK_CONSTANT_DETAILS_SIGNMASK_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Base class for generating signmask constant
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/meta/from_bits.hpp>
#include <nt2/sdk/constant/splat.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>

NT2_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< double_<A0>    > ) )
NT2_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< float_<A0>     > ) )
NT2_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< unsigned_<A0>  > ) )
NT2_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< signed_<A0>    > ) )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct  call< tag::signmask_(tag::target_(tag::double_) )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    NT2_FUNCTOR_CALL(1)
    {
      meta::from_bits<double>::type const that = {0x8000000000000000LL};
      return splat<typename A0::type>(that.value);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_(tag::float_) )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    NT2_FUNCTOR_CALL(1)
    {
      meta::from_bits<float>::type const that = {0x80000000};
      return splat<typename A0::type>(that.value);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_(tag::unsigned_) )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<typename A0::type>::type base;
      return splat<typename A0::type>(0);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_(tag::signed_) )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<typename A0::type>::type base;
      BOOST_STATIC_CONSTANT(base, value = base(1) << (sizeof(base)*CHAR_BIT-1) );
      return splat<typename A0::type>(value);
    }
  };
} }

#endif
