#include <iostream>

template<typename T>
class LinkedList {
private:
	struct Node
	{
		Node* _next; //ptr to next node
		T _data;

		Node(const T& value) : _next(nullptr), _data(data) {}
	};
public:
	//need head of list
	Node* _head;
	
	//tail of list
	Node* _tail;
	std::size_t _listSize;
	
	//linkedlist constructor
	
	//default constructor
	LinkedList() : _tail(nullptr), _head(nullptr), _listSize(0) {}
	
	//create a linked list, given n nodes

	//method to print list 
		//
	//method to add to list
	void push_back(const T& value)
	{
		Node* newNode = new Node(value);
		if (_head == nullptr)
		{
			_head = newNode;
			_tail = newNode;
		}
		else
		{
			_tail->next = newNode; //whatever's at current list tail, make next point to added node
			_tail = newNode; //set tail to added node
		}
		++_listSize;
	}


	//method to push_front
	void push_front(const T& value)
	{
		Node* newNode = new Node(value);
		//(*newNode).next = _head
		newNode->_next = _head; //set newnode's next to be _head
		_head = newNode; //set head to newnode

		if (_tail == nullptr)
		{
			_tail = newNode;
		}
		++_listSize;
	}

	T& operator[](size_t index)
	{
		Node* curr = _head; //set new current node to beginning of list (head)
		//iterate thru list
		// while index < i(0)
		// when index !< i, move current ptr forward by one
			// set current = current->next
		//when index == i
		return current->value;
	}
	
	//method to remove from list
	
};