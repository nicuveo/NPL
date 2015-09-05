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

}



#endif /* !NPL_RANGE_HH_ */
