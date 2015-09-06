//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_PP_ARRAY_SORT_HH_
# define NPL_PP_ARRAY_SORT_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

# include <boost/preprocessor/comparison/less.hpp>
# include <boost/preprocessor/array/insert.hpp>
# include <boost/preprocessor/array/elem.hpp>
# include <boost/preprocessor/array/size.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/while.hpp>
# include <boost/preprocessor/inc.hpp>
# include <boost/preprocessor/cat.hpp>
# include <boost/preprocessor/if.hpp>

# include "array_lower_bound.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Declarations

/*
** Sorts the given PP_ARRAY.
** _U variants remove duplicates.
** _D variants use the next available PP_WHILE iteration
** For examples, see unit tests below.
*/

# define NPL_PP_ARRAY_SORT(A)     NPL_PP_AS_RES(BOOST_PP_WHILE(                  NPL_PP_AS_PRED, NPL_PP_AS_OP,   (A, 0, (0, ()))))
# define NPL_PP_ARRAY_SORT_U(A)   NPL_PP_AS_RES(BOOST_PP_WHILE(                  NPL_PP_AS_PRED, NPL_PP_AS_OP_U, (A, 0, (0, ()))))
# define NPL_PP_ARRAY_SORT_D(A)   NPL_PP_AS_RES(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(NPL_PP_AS_PRED, NPL_PP_AS_OP,   (A, 0, (0, ()))))
# define NPL_PP_ARRAY_SORT_U_D(A) NPL_PP_AS_RES(BOOST_PP_CAT(BOOST_PP_WHILE_, D)(NPL_PP_AS_PRED, NPL_PP_AS_OP_U, (A, 0, (0, ()))))



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Workarounds

/*
** Boost 1.49.0 lacks BOOST_PP_TUPLE_REM_0.
** PP_ARRAY_INSERT documentation examples do not work...
*/

# ifndef BOOST_PP_TUPLE_REM_0
#  define BOOST_PP_TUPLE_REM_0()
# endif



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

# define NPL_PP_AS_LB(D, S) NPL_PP_ARRAY_LOWER_BOUND_D(D, NPL_PP_AS_RES(S), NPL_PP_AS_ARRAY_ELEM(S))

# define NPL_PP_AS_ARRAY_ELEM(S)  BOOST_PP_ARRAY_ELEM(NPL_PP_AS_INDEX(S), NPL_PP_AS_ARRAY(S))
# define NPL_PP_AS_ARRAY_SIZE(S)  BOOST_PP_ARRAY_SIZE(NPL_PP_AS_ARRAY(S))
# define NPL_PP_AS_ARRAY(S)       BOOST_PP_TUPLE_ELEM(3, 0, S)
# define NPL_PP_AS_INDEX(S)       BOOST_PP_TUPLE_ELEM(3, 1, S)
# define NPL_PP_AS_RES(S)         BOOST_PP_TUPLE_ELEM(3, 2, S)

# define NPL_PP_AS_MERGE(  D, E, R, P) BOOST_PP_ARRAY_INSERT_D(D, R, P, E)
# define NPL_PP_AS_MERGE_R(D, E, R, P) BOOST_PP_IF(BOOST_PP_LESS(E, BOOST_PP_ARRAY_ELEM(P, R)), NPL_PP_AS_MERGE(D, E, R, P), R)
# define NPL_PP_AS_MERGE_U(D, E, R, P) BOOST_PP_IF(BOOST_PP_LESS(P, BOOST_PP_ARRAY_SIZE(R)), NPL_PP_AS_MERGE_R, NPL_PP_AS_MERGE)(D, E, R, P)

# define NPL_PP_AS_PRED(D, S) BOOST_PP_LESS_D(D, NPL_PP_AS_INDEX(S), NPL_PP_AS_ARRAY_SIZE(S))
# define NPL_PP_AS_OP(  D, S) (NPL_PP_AS_ARRAY(S), BOOST_PP_INC(NPL_PP_AS_INDEX(S)), NPL_PP_AS_MERGE  (D, NPL_PP_AS_ARRAY_ELEM(S), NPL_PP_AS_RES(S), NPL_PP_AS_LB(D, S)))
# define NPL_PP_AS_OP_U(D, S) (NPL_PP_AS_ARRAY(S), BOOST_PP_INC(NPL_PP_AS_INDEX(S)), NPL_PP_AS_MERGE_U(D, NPL_PP_AS_ARRAY_ELEM(S), NPL_PP_AS_RES(S), NPL_PP_AS_LB(D, S)))



#endif /* !NPL_PP_ARRAY_SORT_HH_ */
