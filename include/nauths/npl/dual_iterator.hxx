// for project npl

#ifndef NPL_DUAL_ITERATOR_HXX_
# define NPL_DUAL_ITERATOR_HXX_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "dual_iterator.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace npl
{


  // constructors

  template <typename C>
  DualIterator<C>::DualIterator()
  {
  }

  template <typename C>
  template <typename I>
  DualIterator<C>::DualIterator(I const& other)
    : AdaptorType(other), b_(other.b_), e_(other.e_)
  {
  }

  template <typename C>
  template <typename I>
  DualIterator<C>::DualIterator(I const& b, I const& e, I const& i)
    : AdaptorType(i), b_(b), e_(e)
  {
  }


  // internal operations

  template <typename C>
  inline typename DualIterator<C>::Dual
  DualIterator<C>::dereference() const
  {
    IteratorType i1 = this->base_reference();
    IteratorType i2 = i1;

    if (++i2 == e_)
      i2 = b_;

    return boost::tie(*i1, *i2);
  }


  // helpers

  template <typename C>
  inline DualIterator<C> begin(C const& c)
  {
    return DualIterator<C>(c.begin(), c.end(), c.begin());
  }

  template <typename C>
  inline DualIterator<C> end(C const& c)
  {
    return DualIterator<C>(c.begin(), c.end(), c.end());
  }

  template <typename C>
  inline Range< DualIterator<C> > range(C const& c)
  {
    return std::make_pair(begin(c), end(c));
  }


  template <typename T1, typename T2>
  inline typename boost::call_traits<T1>::const_reference
  first(boost::tuple<T1, T2> const& dt)
  {
    return dt.template get<0>();
  }

  template <typename T1, typename T2>
  inline typename boost::call_traits<T2>::const_reference
  second(boost::tuple<T1, T2> const& dt)
  {
    return dt.template get<1>();
  }


}



#endif /* !NPL_DUAL_ITERATOR_HXX_ */
