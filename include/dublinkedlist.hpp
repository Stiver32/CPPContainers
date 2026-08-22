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

	class Iterator
	{
	private: 
		Node* _current;
		  
	public: 
		Iterator(Node* node) : _current(node) {}

		T& operator*() //give data stored at current node
		{
			return _current->_data; 
		}
		Iterator& operator++() // pre-increment operator to move to the next node
		{
			_current = _current->_next;
			return *this;
		}

		bool operator!=(const Iterator& other) const
		{
			return _current != other._current;
		}
	};

	// Default
	DoublyLinkedList() : _head(nullptr), _tail(nullptr), _listSize(0) {}

	// Copy Constructor
	DoublyLinkedList(const DoublyLinkedList& other) : _tail(nullptr), _head(nullptr),_listSize(0)
	{
		Node* curr = other._head;
		while (curr != nullptr)
		{
			push_back(curr->_data);
			curr = curr->_next;
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
	DoublyLinkedList(DoublyLinkedList&& other) noexcept : _head(other._head),_tail(other._tail),_listSiz(other._listSize)
	{
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

	/*    ** MEMBER FUNCTIONS **    */

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

	void push_front(const T& value)
	{
		Node* newNode = new Node(value);
		if (_head == nullptr)
		{
			_head = newNode;
			_tail = newNode;
		}
		else
		{
			newNode->_next = _head;
			_head->_prev = newNode;
			_head = newNode;
		}
		++_listSize;
	}

	//remove back of list
	void pop_back()
	{
		if (empty()) {
			throw std::out_of_range("List is empty.");
		}

		if (_head == _tail)
		{
			delete _head;
			_head = nullptr;
			_tail = nullptr;
			_listSize = 0;
			return;
		}
		Node* curr = _tail->_prev;
		delete _tail;
		_tail = curr;
		_tail->_next = nullptr;
		--_listSize;

	}

	// replaced get() with iterator...see NOTES.md


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

	size_t size() const
	{
		return _listSize;
	}

	bool empty() const
	{
		return _listSize == 0;
	}

	// Traversal
	Iterator begin() // give iterator pointing at first node
	{
		return Iterator(_head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	~DoublyLinkedList()
	{
		clear();
	}
};