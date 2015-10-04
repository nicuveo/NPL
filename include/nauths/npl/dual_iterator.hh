//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_DUAL_ITERATOR_HH_
# define NPL_DUAL_ITERATOR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <tuple>
# include <boost/iterator/iterator_adaptor.hpp>
# include <boost/call_traits.hpp>
# include "nauths/npl/range.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace npl
{

  // internal helpers

  namespace il
  {

    template <typename C>
    struct DualTrait
    {
      public:
        typedef C                                              Container;
        typedef typename Container::value_type                 Value;
        typedef typename Container::const_iterator             Iterator;
        typedef typename boost::call_traits<Value>::param_type Ref;
        typedef std::tuple<Ref, Ref>                           Dual;
    };

    template <typename E, typename C>
    struct AdaptorTrait
    {
      public:
        typedef typename DualTrait<C>::Iterator Iterator;
        typedef typename DualTrait<C>::Dual     Dual;
        typedef boost::iterator_adaptor<
          E,
          Iterator,
          Dual,
          boost::use_default,
          Dual>                                 Adaptor;
    };

  }


  // dual iterator

  template <typename C>
  class DualIterator : public il::AdaptorTrait<DualIterator<C>, C>::Adaptor
  {
    public:
      // types

      typedef DualIterator<C>                             Self;
      typedef il::DualTrait<C>                            Trait;
      typedef typename il::AdaptorTrait<Self, C>::Adaptor Adaptor;
      typedef typename Trait::Iterator                    Iterator;
      typedef typename Trait::Dual                        Dual;
      typedef typename Trait::Ref                         Ref;


      // constructors

      DualIterator();

      template <typename I>
      DualIterator(I const& other);

      template <typename I>
      DualIterator(I const& b, I const& e, I const& i);


    private:
      // boost internals

      friend class boost::iterator_core_access;


      // internal operations

      Dual dereference() const;


      // data

      Iterator b_;
      Iterator e_;
  };


  // dual trait

  template <typename C>
  struct Dual
  {
    public:
      typedef typename DualIterator<C>::Dual Type;
  };


  // helpers

  template <typename C> DualIterator<C>          dual_begin(C const& c);
  template <typename C> DualIterator<C>          dual_end  (C const& c);
  template <typename C> Range< DualIterator<C> > dual_range(C const& c);


  template <typename T1, typename T2>
  typename boost::call_traits<T1>::const_reference first (std::tuple<T1, T2> const& dt);
  template <typename T1, typename T2>
  typename boost::call_traits<T2>::const_reference second(std::tuple<T1, T2> const& dt);

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/npl/dual_iterator.hxx"



#endif /* !NPL_DUAL_ITERATOR_HH_ */
