/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_BUFFER_HPP_INCLUDED
#define NT2_SDK_MEMORY_BUFFER_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Data buffer with NRC like interface
// Basically a std::vector that copes well with bool and use NRC like allocation
// interface and parametrization
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/error/assert.hpp>
#include <nt2/sdk/memory/allocator.hpp>
#include <nt2/sdk/memory/details/buffer_base.hpp>

namespace nt2 { namespace memory
{
  template<class Type,class Allocator = nt2::memory::allocator<Type> >
  class buffer
      : private details::buffer_data< typename Allocator
                                      ::template rebind<Type>::other::pointer
                                    >
      , private Allocator::template rebind<Type>::other
  {
    public:

    typedef typename Allocator::template rebind<Type>::other  parent_allocator;
    typedef details::buffer_data<typename parent_allocator::pointer> parent_data;

    ////////////////////////////////////////////////////////////////////////////
    // Forwarded types
    ////////////////////////////////////////////////////////////////////////////
    typedef typename parent_allocator::value_type       value_type;
    typedef typename parent_allocator::pointer          pointer;
    typedef typename parent_allocator::const_pointer    const_pointer;
    typedef typename parent_allocator::reference        reference;
    typedef typename parent_allocator::const_reference  const_reference;
    typedef typename parent_allocator::size_type        size_type;
    typedef typename parent_allocator::difference_type  difference_type;
    typedef typename parent_allocator::difference_type  index_type;

    ////////////////////////////////////////////////////////////////////////////
    // Constructor & destructor
    ////////////////////////////////////////////////////////////////////////////
    buffer( Allocator const& a = Allocator() )
          : parent_data(), parent_allocator(a)
    {
      parent_data::allocate(0,0,allocator());
    }

    template<class Base, class Size>
    buffer( Base const& b
          , Size const& s
          , Allocator const& a = Allocator()
          )
          : parent_data(), parent_allocator(a)
    {
      parent_data::allocate(b,s,allocator());
    }

    ~buffer() { parent_data::deallocate(allocator()); }

    buffer& operator=(buffer const& src)
    {
      if(!size()) parent_data::allocate(src.lower(),src.size(),allocator());
      else        restructure(src.lower(), src.size());

      allocator() = src.allocator();
      std::copy(src.begin(),src.end(),begin());
    }

    ////////////////////////////////////////////////////////////////////////////
    // Iterator related methods
    ////////////////////////////////////////////////////////////////////////////
    using parent_data::begin;
    using parent_data::end;

    ////////////////////////////////////////////////////////////////////////////
    // Forward size related methods
    ////////////////////////////////////////////////////////////////////////////
    using parent_data::lower;
    using parent_data::upper;
    using parent_data::size;

    ////////////////////////////////////////////////////////////////////////////
    // RandomAccessContainer Interface
    ////////////////////////////////////////////////////////////////////////////
    typename parent_allocator::reference
    operator[](typename parent_allocator::difference_type const& i)
    {
      NT2_ASSERT( (i >= lower()) && (i <= upper()) );
      return parent_data::begin_[i];
    }

    typename parent_allocator::const_reference
    operator[](typename parent_allocator::difference_type const& i) const
    {
      NT2_ASSERT( (i >= lower()) && (i <= upper()) );
      return parent_data::begin_[i];
    }

    ////////////////////////////////////////////////////////////////////////////
    // Swapping
    ////////////////////////////////////////////////////////////////////////////
    void swap( buffer& src )
    {
      parent_data::swap(src);
      boost::swap(allocator(),src.allocator());
    }

    ////////////////////////////////////////////////////////////////////////////
    // resize/rebase buffer
    ////////////////////////////////////////////////////////////////////////////
    using parent_data::rebase;

    template<class Size>
    void resize(Size s) { parent_data::resize(s,allocator()); }

    template<class Base,class Size>
    void restructure( Base const& b, Size const& s )
    {
      resize(s);
      rebase(b);
    }

    protected:
    ////////////////////////////////////////////////////////////////////////////
    // Allocator access
    ////////////////////////////////////////////////////////////////////////////
    parent_allocator& allocator()
    {
      return static_cast<parent_allocator&>(*this);
    }

    parent_allocator const& allocator() const
    {
      return static_cast<parent_allocator const&>(*this);
    }
  };

  //////////////////////////////////////////////////////////////////////////////
  // ADL swap
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class Allocator>
  void swap( buffer<T,Allocator>& a, buffer<T,Allocator>& b )
  {
    a.swap(b);
  }
} }

#endif
