//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Includes

#include <cstdlib>
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "nauths/npl/real.hh"



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Implementation

BOOST_AUTO_TEST_SUITE(real)

BOOST_AUTO_TEST_CASE(real_00)
{
  npl::Real<double, -2> r0(0.00001);
  npl::Real<double, -2> r1(0.99999);
  npl::Real<double, -2> r2(0.01001);
  npl::Real<double, -2> r3(0.99000);

  BOOST_REQUIRE_CLOSE(r0.nearest(), 0.00, 0.000001);
  BOOST_REQUIRE_CLOSE(r1.nearest(), 1.00, 0.000001);
  BOOST_REQUIRE_CLOSE(r2.nearest(), 0.01, 0.000001);
  BOOST_REQUIRE_CLOSE(r3.nearest(), 0.99, 0.000001);
}

BOOST_AUTO_TEST_SUITE_END()
