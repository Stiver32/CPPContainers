#include "doctest.h"
#include "../include/linkedlist.hpp"






//TEST_CASE("Vector - push back")
//{
//	mVector<int>v(7);
//	v.push_back(8);
//	CHECK(v[7] == 8);
//
//}
//
//TEST_CASE("Vector - pop back")
//{
//	mVector<int>v(7);
//	v.pop_back();
//	CHECK(v.getSize() == 6);
//}
//
//TEST_CASE("Vector - pop back - empty")
//{
//	mVector<int>v;
//	v.pop_back();
//	CHECK(v.getSize() == 0);
//}
//
//TEST_CASE("Vector - [] operator")
//{
//	mVector<int>v(5);
//	CHECK(v[4] == 0);
//	v[4] = 5;
//	CHECK(v[4] == 5);
//}
//
//TEST_CASE("Vector - beginning")
//{
//	mVector<int>v(5);
//
//	for (int i = 0; i < v._capacity; i++)
//	{
//		v[i] = i;
//	}
//	CHECK(v.front() == 0);
//}



//TEST_CASE("Vector - front")
//{
//	LinkedList<char>a;
//	a.push_back('a');
//	CHECK(a.front() == 'a');
//}
//
//TEST_CASE("Vector - back")
//{
//	LinkedList<char>a;
//	a.push_back('a');
//	CHECK(a.back() == 'a');
//}

TEST_CASE("Vector - move assignment")
{
	LinkedList<int> a;
	a.push_back(1);
	a.push_back(2);

	LinkedList<int> b;
	b = std::move(a); // invoke move assignment 
	
	
	CHECK(b.size() == 2);
	CHECK(b.getCapacity() == 3);
	CHECK(a.getSize() == 0);
	CHECK(a.getCapacity() == 0);
	CHECK(a.begin() == nullptr);
}

TEST_CASE("LinkedList - copy constructor")
{
	LinkedList<int> a;
	a.push_back(1);
	a.push_back(2);

	LinkedList<int> b = a; // invoke copy constructor
	CHECK(b.size() == 2);

	CHECK(b.get(0) == 1);
	CHECK(a.size() == 2);


	b.push_back(3);
	CHECK(b.size() == 3);
	CHECK(a.size() == 2); //remains unchanged
}

TEST_CASE("Test LinkedList Size & LinkedList constructor with size argument")
{
	LinkedList<int> ll(5);

	REQUIRE(ll._listSize == 5);
	REQUIRE(ll.size() == 5);
	CHECK(ll._listSize == 5);
	CHECK(ll.size() == 5);
}

TEST_CASE("Vector - move constructor")
{
	LinkedList<int>a;
	a.push_back(1);
	a.push_back(2);

	LinkedList<int>b = std::move(a); //invoke move

	CHECK(b.size() == 2);
	CHECK(b[0] == 1);
	CHECK(a.size() == 0);
	CHECK(a.begin() == nullptr);

}



