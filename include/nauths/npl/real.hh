//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_REAL_HH_
# define NPL_REAL_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/call_traits.hpp>
# include <limits>
# include <cmath>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

namespace npl
{

  template <typename T, int P>
  class Real
  {
    public:
      typedef T ValueType;

      template <typename U>
      Real(U const& r) : data_(r) {}
      Real(T r = T())  : data_(r) {}

      template <typename U>
      Real& operator=(U const& r) { data_ = r; return *this; }
      Real& operator=(T r)        { data_ = r; return *this; }

      operator T() const          { return data_;            }
      operator T&()               { return data_;            }

      T nearest() const;

      Real& round();
      Real  rounded() const;

      static const T epsilon;

    private:
      T data_;
  };


  template <typename T, int P>
  const T Real<T, P>::epsilon = std::pow(T(10), P);


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Traits

namespace std
{

  template <class T, int P>
  class numeric_limits<npl::Real<T, P> > : public numeric_limits<T>
  {
  };

}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

namespace npl
{

  template <typename T, int P>
  inline T
  Real<T, P>::nearest() const
  {
    return epsilon * std::floor((data_ / epsilon) + T(1) / 2);
  }

  template <typename T, int P>
  inline Real<T, P>&
  Real<T, P>::round()
  {
    data_ = nearest();
    return this;
  }

  template <typename T, int P>
  inline Real<T, P>
  Real<T, P>::rounded() const
  {
    return nearest();
  }


}



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Comparison operators

template <typename T, int P>
inline bool operator<(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return (T(r1) == T(r2) ? false : ((T(r2) - T(r1)) >= npl::Real<T, P>::epsilon));
}

template <typename T, int P>
inline bool operator<=(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return (T(r1) == T(r2) ? true : ((T(r2) - T(r1)) > -npl::Real<T, P>::epsilon));
}

template <typename T, int P>
inline bool operator==(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return (T(r1) == T(r2) ? true : (std::abs(T(r2) - T(r1)) < npl::Real<T, P>::epsilon));
}

template <typename T, int P>
inline bool operator>(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return (r2 < r1);
}

template <typename T, int P>
inline bool operator>=(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return (r2 <= r1);
}

template <typename T, int P>
inline bool operator!=(npl::Real<T, P> const& r1, npl::Real<T, P> const& r2)
{
  return not (r1 == r2);
}



#endif /* !NPL_REAL_HH_ */
