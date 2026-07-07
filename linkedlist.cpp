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

	T& get(size_t index)
	{
		if (index >= _listSize)
		{
			throw std::out_of_range("index out of range");
		}
		Node* curr = _head; //set new current node to beginning of list (head)
		//iterate thru list
		// while index < i(0)
		// when index !< i, move current ptr forward by one
		for (std::size_t i = 0; i < index; ++i)
		{
			// set current = current->next
			curr = curr->_next;
		}
			
		return curr->_data;
	}

	const T& get(size_t index)const
	{
		if (index >= _listSize)
		{
			throw std::out_of_range("index out of range");
		}
		Node* curr = _head; //set new current node to beginning of list (head)
		//iterate thru list
		// while index < i(0)
		// when index !< i, move current ptr forward by one
		for (std::size_t i = 0; i < index; ++i)
		{
			// set current = current->next
			curr = curr->_next;
		}

		return curr->_data;
	}
	
	T& front()
	{
		if (empty())
		{

		}
	}
	bool empty() const
	{
		return _listSize == 0;
	}

	//method to remove from list
	
};