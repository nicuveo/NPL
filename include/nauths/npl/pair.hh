//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_PAIR_HH_
# define NPL_PAIR_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <algorithm>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace npl
{

  template <typename T, typename U> inline T const& first (std::pair<T, U> const& p) { return p.first;  }
  template <typename T, typename U> inline U const& second(std::pair<T, U> const& p) { return p.second; }
  template <typename T, typename U> inline T const& begin (std::pair<T, U> const& p) { return p.first;  }
  template <typename T, typename U> inline U const& end   (std::pair<T, U> const& p) { return p.second; }
  template <typename T, typename U> inline T&       first (std::pair<T, U>& p)       { return p.first;  }
  template <typename T, typename U> inline U&       second(std::pair<T, U>& p)       { return p.second; }

}



#endif /* !NPL_PAIR_HH_ */
