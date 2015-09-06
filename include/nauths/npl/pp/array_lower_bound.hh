//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_PP_ARRAY_LOWER_BOUND_HH_
# define NPL_PP_ARRAY_LOWER_BOUND_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/comparison/less.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/array/size.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/inc.hpp>
# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/if.hpp>

# include "discard.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Finds the lower bound of a given element in a given PP_ARRAY.
** Return value is the index of the lower bound is the array.
** The array is considered sorted.
** _D variants use the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define NPL_PP_ARRAY_LOWER_BOUND(     A, E) NPL_PP_ALB_INDEX(BOOST_PP_WHILE(                  NPL_PP_ALB_PRED, NPL_PP_ALB_OP, (A, E, 0)))
# define NPL_PP_ARRAY_LOWER_BOUND_D(D, A, E) NPL_PP_ALB_INDEX(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(NPL_PP_ALB_PRED, NPL_PP_ALB_OP, (A, E, 0)))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define NPL_PP_ALB_ARRAY_ELEM_IMPLEM(D, A, S, I) BOOST_PP_IF(BOOST_PP_LESS_D(D, I, S), BOOST_PP_ARRAY_ELEM, NPL_PP_DISCARD_MAX_2)(I, A)

# define NPL_PP_ALB_ARRAY_ELEM(D, S) NPL_PP_ALB_ARRAY_ELEM_IMPLEM(D, NPL_PP_ALB_ARRAY(S), NPL_PP_ALB_ARRAY_SIZE(S), NPL_PP_ALB_INDEX(S))
# define NPL_PP_ALB_ARRAY_SIZE(S)    BOOST_PP_ARRAY_SIZE(NPL_PP_ALB_ARRAY(S))
# define NPL_PP_ALB_ARRAY(S)         BOOST_PP_TUPLE_ELEM(3, 0, S)
# define NPL_PP_ALB_BOUND(S)         BOOST_PP_TUPLE_ELEM(3, 1, S)
# define NPL_PP_ALB_INDEX(S)         BOOST_PP_TUPLE_ELEM(3, 2, S)

# define NPL_PP_ALB_PRED(D, S) BOOST_PP_LESS_D(D, NPL_PP_ALB_ARRAY_ELEM(D, S), NPL_PP_ALB_BOUND(S))
# define NPL_PP_ALB_OP(D, S) (NPL_PP_ALB_ARRAY(S), NPL_PP_ALB_BOUND(S), BOOST_PP_INC(NPL_PP_ALB_INDEX(S)))



#endif /* !NPL_PP_ARRAY_LOWER_BOUND_HH_ */
