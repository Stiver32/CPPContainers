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

	// Copy Constructor
	DoublyLinkedList(const DoublyLinkedList& other)
	{
		_tail = nullptr;
		_head = nullptr;
		_listSize = 0;

		Node* curr = other._head;
		while (curr != nullptr)
		{
			push_back(curr->_data);
			curr = curr->next;
		}
		
	}

	// Copy Assignment Operator
	DoublyLinkedList& operator=(const DoublyLinkedList& other)
	{
		if (this == &other) return *this;
		clear();

		Node* curr = other._head;

		while (curr != nullptr)
		{
			push_back(curr->_data); //add node to back of list
			curr = curr->_next;
		}
		return *this;

	}

	// Move Constructor
	DoublyLinkedList(DoublyLinkedList&& other) noexcept
	{
		_head = other._head;
		_tail = other._tail;
		_listSize = other._listSize;
		other._head = nullptr;
		other._tail = nullptr;
		other._listSize = 0;
	}

	//Move Assignment 

	DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept
	{
		if (this == &other) return *this;
		clear();
		_head = other._head;
		_tail = other._tail;
		_listSize = other._listSize;
		other._head = nullptr;
		other._tail = nullptr;
		other._listSize = 0;
		return *this;
	}


	void push_back(const T& value)
	{
		Node* newNode = new Node(value);
		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
		}
		else {
			_tail->_next = newNode;
			newNode->_prev = _tail;
			_tail = newNode;
		}
		++_listSize;
	}

	void clear()
	{
		Node* curr = _head;
		while (curr != nullptr)
		{
			Node* temp = curr->_next;
			delete curr;
			curr = temp;
		}
		_head = nullptr;
		_tail = nullptr;
		_listSize = 0;
	}

};