//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_PP_DISCARD_HH_
# define NPL_PP_DISCARD_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/config/limits.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

// # define NPL_PP_DISCARD(...)
// # define NPL_PP_DISCARD_MIN(...) 0
// # define NPL_PP_DISCARD_MAX(...) BOOST_PP_LIMIT_MAG

# define NPL_PP_DISCARD_1(a)
# define NPL_PP_DISCARD_2(a, b)
# define NPL_PP_DISCARD_3(a, b, c)
# define NPL_PP_DISCARD_4(a, b, c, d)
# define NPL_PP_DISCARD_5(a, b, c, d, e)
# define NPL_PP_DISCARD_6(a, b, c, d, e, f)
# define NPL_PP_DISCARD_7(a, b, c, d, e, f, g)
# define NPL_PP_DISCARD_8(a, b, c, d, e, f, g, h)
# define NPL_PP_DISCARD_9(a, b, c, d, e, f, g, h, i)

# define NPL_PP_DISCARD_MIN_1(a)                         0
# define NPL_PP_DISCARD_MIN_2(a, b)                      0
# define NPL_PP_DISCARD_MIN_3(a, b, c)                   0
# define NPL_PP_DISCARD_MIN_4(a, b, c, d)                0
# define NPL_PP_DISCARD_MIN_5(a, b, c, d, e)             0
# define NPL_PP_DISCARD_MIN_6(a, b, c, d, e, f)          0
# define NPL_PP_DISCARD_MIN_7(a, b, c, d, e, f, g)       0
# define NPL_PP_DISCARD_MIN_8(a, b, c, d, e, f, g, h)    0
# define NPL_PP_DISCARD_MIN_9(a, b, c, d, e, f, g, h, i) 0

# define NPL_PP_DISCARD_MAX_1(a)                         BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_2(a, b)                      BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_3(a, b, c)                   BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_4(a, b, c, d)                BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_5(a, b, c, d, e)             BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_6(a, b, c, d, e, f)          BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_7(a, b, c, d, e, f, g)       BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_8(a, b, c, d, e, f, g, h)    BOOST_PP_LIMIT_MAG
# define NPL_PP_DISCARD_MAX_9(a, b, c, d, e, f, g, h, i) BOOST_PP_LIMIT_MAG



#endif /* !NPL_PP_DISCARD_HH_ */
