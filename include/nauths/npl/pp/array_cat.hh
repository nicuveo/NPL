//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_PP_ARRAY_CAT_HH_
# define NPL_PP_ARRAY_CAT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/array/push_back.hpp>
# include <boost/preprocessor/array/pop_front.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/cat.hpp>



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Concatenates two PP_ARRAYs.
** _D variant uses the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define NPL_PP_ARRAY_CAT(     A1, A2) NPL_PP_AC_1(                  BOOST_PP_WHILE(NPL_PP_AC_PRED, NPL_PP_AC_OP, (A1, A2)))
# define NPL_PP_ARRAY_CAT_D(D, A1, A2) NPL_PP_AC_1(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(NPL_PP_AC_PRED, NPL_PP_AC_OP, (A1, A2)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define NPL_PP_AC_1(S) BOOST_PP_TUPLE_ELEM(2, 0, S)
# define NPL_PP_AC_2(S) BOOST_PP_TUPLE_ELEM(2, 1, S)
# define NPL_PP_AC_PRED(D, S) BOOST_PP_ARRAY_SIZE(NPL_PP_AC_2(S))
# define NPL_PP_AC_OP(  D, S) (BOOST_PP_ARRAY_PUSH_BACK(NPL_PP_AC_1(S), BOOST_PP_ARRAY_ELEM(0, NPL_PP_AC_2(S))), BOOST_PP_ARRAY_POP_FRONT(NPL_PP_AC_2(S)))



#endif /* !NPL_PP_ARRAY_CAT_HH_ */
