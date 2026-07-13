#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  
#include "doctest.h"

#include "../include/vector.hpp"
#include "../include/linkedlist.hpp"

#include <iostream>

TEST_CASE("testing function")
{
	mVector<int> v(5);
	
	REQUIRE(v._size == 5);
	REQUIRE(v._capacity == 5);
	CHECK(v._size == 5);
}