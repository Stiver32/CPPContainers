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
	//method to remove from list
	
};