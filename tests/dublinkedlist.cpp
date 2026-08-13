#include <iostream>

template<typename T>

class DoublyLinkedList
{
private:
	struct Node
	{
		Node* _next;
		Node* _prev;
		T _data;

		Node(const T& data) : _next(nullptr), _prev(nullptr), _data(data) {}
	};

	Node* _head;
	Node* _tail;
	size_t _listSize;

public:

	// Default
	DoublyLinkedList() : _head(nullptr), _tail(nullptr), _listSize(0) {}

	//// Copy Constructor
	//DoublyLinkedList(const DoublyLinkedList& other)
	//{
	//	_tail = nullptr;
	//	_head = nullptr;
	//	_listSize = 0;

	//	Node* curr = other._head;
	//	
	//}


	//void push_back(const T& value)
	//{
	//	Node* newNode = new Node(value);
	//	newNode->next

	//}
	
	
};