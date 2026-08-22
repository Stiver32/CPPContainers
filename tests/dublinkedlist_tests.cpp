#include "doctest.h"
#include "../include/dublinkedlist.hpp"



TEST_CASE("DoublyLinkedList - pop back - empty")
{
	DoublyLinkedList<int>v;
	v.pop_back();
	CHECK(v.size() == 0);
}


TEST_CASE("LinkedList - front")
{
	DoublyLinkedList<char>a;
	a.push_back('a');
	CHECK(a.front() == 'a');
}

TEST_CASE("LinkedList - back")
{
	DoublyLinkedList<char>a;
	a.push_back('a');
	CHECK(a.back() == 'a');
}

TEST_CASE("LinkedList - move assignment")
{
	DoublyLinkedList<int> a;
	a.push_back(1);
	a.push_back(2);

	DoublyLinkedList<int> b;
	b = std::move(a); // invoke move assignment 


	CHECK(b.size() == 2);
	CHECK(a.size() == 0);

	//CHECK(a.begin() == nullptr);
}

TEST_CASE("DoublyLinkedList - copy constructor")
{
	DoublyLinkedList<int> a;
	a.push_back(1);
	a.push_back(2);

	DoublyLinkedList<int> b = a; // invoke copy constructor
	CHECK(b.size() == 2);

	CHECK(b.get(0) == 1);
	CHECK(a.size() == 2);


	b.push_back(3);
	CHECK(b.size() == 3);
	CHECK(a.size() == 2); //remains unchanged
}

TEST_CASE("Test DoublyLinkedList Size & DoublyLinkedList constructor with size argument")
{
	DoublyLinkedList<int> ll(5);

	REQUIRE(ll.size() == 5);
	CHECK(ll.size() == 5);
}

TEST_CASE("DoublyLinkedList - move constructor")
{
	DoublyLinkedList<int>a;
	a.push_back(1);
	a.push_back(2);

	DoublyLinkedList<int>b = std::move(a); //invoke move

	CHECK(b.size() == 2);
	CHECK(b.get(0) == 1);
	CHECK(a.size() == 0);
	//CHECK(a.begin() == nullptr);

}



