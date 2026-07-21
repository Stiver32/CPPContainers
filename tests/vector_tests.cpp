#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  
#include "doctest.h"

#include "../include/vector.hpp"
#include "../include/linkedlist.hpp"

#include <iostream>

TEST_CASE("Test Vector size and capacity")
{
	mVector<int> v(5);
	
	REQUIRE(v._size == 5);
	REQUIRE(v._capacity == 5);
	CHECK(v._size == 5);
}


TEST_CASE("Vector - push back")
{
	mVector<int>v(7);
	v.push_back(8);
}

TEST_CASE("Vector - pop back")
{

}

TEST_CASE("Vector - [] operator")
{
	mVector<int>v(5);
	CHECK(v[4] == 0);
	v[4] = 5;
	CHECK(v[4] == 5);
}

TEST_CASE("Vector - beginning")
{
	mVector<int>v(5);

	for (int i = 0; i < v._capacity; i++)
	{
		v[i] = i;
	}
	CHECK(v.front() == 0);
}

































































































