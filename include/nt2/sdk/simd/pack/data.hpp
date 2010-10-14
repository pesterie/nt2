/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_PACK_DATA_HPP_INCLUDED
#define NT2_SDK_SIMD_PACK_DATA_HPP_INCLUDED

#include <nt2/sdk/simd/native.hpp>
#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/sdk/dsl/category.hpp>
#include <nt2/sdk/dsl/proto/visitor.hpp>
#include <nt2/sdk/simd/meta/vector_of.hpp>

namespace nt2 { namespace simd
{
  ////////////////////////////////////////////////////////////////////////////
  // data is a tag-dispatched SIMD entity that selects between a native
  // or emulated implementation depending on Type and Cardinal
  ////////////////////////////////////////////////////////////////////////////
  template<class Type,class Cardinal>
  struct  data
  {
    typedef typename meta::vector_of<Type,Cardinal::value>::type  parent;

    typedef boost::proto::visitor < dsl::compute_transform< boost::mpl::_1
                                                          , parent
                                                          >
                                  , dsl::grammar<boost::mpl::_1>
                                  >                               evaluator_type;

    typedef typename meta::category_of<parent>::type  parent_tag;
    typedef functors::ast_<parent_tag>                nt2_category_tag;
    typedef typename parent::value_type               value_type;

    ////////////////////////////////////////////////////////////////////////////
    // Constructors from various sources
    ////////////////////////////////////////////////////////////////////////////
    data() : mData() {}

    void fill(Type const& a0)
    {
      fill(a0,typename meta::is_native<parent>::type());
    }

    Type operator[](int i) const { return mData[i]; }

    ////////////////////////////////////////////////////////////////////////////
    // Fill current data by evaluating soem expression
    ////////////////////////////////////////////////////////////////////////////
    template<class X> void evaluate(expression<X,Type,Cardinal> const& xpr )
    {
      evaluate(xpr,typename meta::is_native<parent>::type());
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return internal value
    ////////////////////////////////////////////////////////////////////////////
    parent const& value() const
    {
      return mData;
    }

    private:
    parent mData;

    private:
    ////////////////////////////////////////////////////////////////////////////
    // Inner evaluation dispatched on native category
    // true_  => native
    ////////////////////////////////////////////////////////////////////////////
    void fill(Type const& a0, boost::mpl::true_ const&)
    {
      mData = splat<parent>(a0);
    }

    template<class X>
    void evaluate ( expression<X,Type,Cardinal> const& xpr
                  , boost::mpl::true_ const&
                  )
    {
      evaluator_type eval;
      mData = eval(xpr);
    }

    ////////////////////////////////////////////////////////////////////////////
    // false_ => array
    ////////////////////////////////////////////////////////////////////////////
    void fill(Type const& a0, boost::mpl::false_ const&)
    {
      mData.fill(a0);
    }

    template<class X>
    void evaluate ( expression<X,Type,Cardinal> const& xpr
                  , boost::mpl::false_ const&
                  )
    {
      evaluator_type eval;
      for(std::size_t i=0;i<Cardinal::value;++i)
        mData[i] = eval(xpr,i,i);
    }
  };
} }

#endif