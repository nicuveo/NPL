//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_RANGE_HH_
# define NPL_RANGE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include "nauths/npl/pair.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace npl
{

  template <typename T>
  class Range : public std::pair<T, T>
  {
    public:
      using std::pair<T, T>::pair;

      T const& begin() const { return this->first;  }
      T const& end()   const { return this->second; }
  };

  template <typename C>
  Range<typename C::const_iterator> range(C const& c)
  {
    return Range<typename C::const_iterator>(c.begin(), c.end());
  }

  template <typename C>
  Range<typename C::iterator> range(C& c)
  {
    return Range<typename C::iterator>(c.begin(), c.end());
  }

  template <typename C>
  Range<typename C::const_reverse_iterator> rrange(C const& c)
  {
    return Range<typename C::const_reverse_iterator>(c.rbegin(), c.rend());
  }

  template <typename C>
  Range<typename C::reverse_iterator> rrange(C& c)
  {
    return Range<typename C::reverse_iterator>(c.rbegin(), c.rend());
  }

}



#endif /* !NPL_RANGE_HH_ */
