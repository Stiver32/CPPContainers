#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  
#include "doctest.h"

#include "../include/vector.hpp"
#include "../include/linkedlist.hpp"



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
	CHECK(v[7] == 8);

}

TEST_CASE("Vector - pop back")
{
	mVector<int>v(7);
	v.pop_back();
	CHECK(v.getSize() == 6); 
}

TEST_CASE("Vector - pop back - empty")
{
	mVector<int>v;
	v.pop_back();
	CHECK(v.getSize() == 0);
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

TEST_CASE("Vector - move constructor")
{
	mVector<int>a;
	a.push_back(1);
	a.push_back(2);

	mVector<int>b = std::move(a); //invoke move

	CHECK(b.getSize() == 2);
	CHECK(b.getCapacity() == 3);
	CHECK(b[0] == 1);
	CHECK(a.getSize() == 0);
	CHECK(a.getCapacity() == 0);
	CHECK(a.begin() == nullptr);

}

TEST_CASE("Vector - move assignment")
{
	mVector<int> a; 
	a.push_back(1);
	a.push_back(2);

	mVector<int> b; 
	b = std::move(a); // invoke move assignment 
	
	CHECK(b.getSize() == 2);
	CHECK(b.getCapacity() == 3);
	CHECK(a.getSize() == 0);
	CHECK(a.getCapacity() == 0);
	CHECK(a.begin() == nullptr);
}

TEST_CASE("Vector - copy constructor")
{
	mVector<int> a;
	a.push_back(1);
	a.push_back(2);

	mVector<int> b = a; // invoke copy constructor
	CHECK(b.getSize() == 2);
	CHECK(b.getCapacity() == 3);
	CHECK(b[0] == 1);
	CHECK(a.getSize() == 2);
	CHECK(a.getCapacity() == 3);

	b.push_back(3);
	CHECK(b.getSize() == 3);
	CHECK(a.getSize() == 2); //remains unchanged
}

TEST_CASE("Vector - front")
{
	mVector<char>a;
	a.push_back('a');
	CHECK(a.front() == 'a');
}

TEST_CASE("Vector - back")
{
	mVector<char>a;
	a.push_back('a');
	CHECK(a.back() == 'a');
}

