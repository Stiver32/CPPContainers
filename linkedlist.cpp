#include <iostream>

template<typename T>
class LinkedList {
private:
	struct Node {
		Node* _next; //ptr to next node
		T _data;
		Node(const T& data) : _next(nullptr), _data(data) {}
	};
public:

	Node* _head; //head of list
	Node* _tail; //tail of list
	std::size_t _listSize;

	//linkedlist constructor

	//default constructor
	LinkedList() : _tail(nullptr), _head(nullptr), _listSize(0) {}

	//create a linked list, given n nodes

	//method to print list 

	//method to add to list
	void push_back(const T& value) {
		Node* newNode = new Node(value);
		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
		}
		else {
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

		if (_tail == nullptr) {
			_tail = newNode;
		}
		++_listSize;
	}
	T& get(size_t index) {
		if (index >= _listSize) {
			throw std::out_of_range("index out of range");
		}
		Node* curr = _head; //set new current node to beginning of list (head)
		//iterate thru list
		// while index < i(0)
		// when index !< i, move current ptr forward by one
		for (std::size_t i = 0; i < index; ++i) {
			// set current = current->next
			curr = curr->_next;
		}
	}

	//const get() so method is callable on const obj
	const T& get(size_t index)const {
		if (index >= _listSize) {
			throw std::out_of_range("index out of range");
		}
		Node* curr = _head; //set new current node to beginning of list (head)
		//iterate thru list
		// while index < i(0)
		// when index !< i, move current ptr forward by one
		for (std::size_t i = 0; i < index; ++i) {
			// set current = current->next
			curr = curr->_next;
		}

		return curr->_data;
	}

	//NOTE: If the function observes but returns access to internal data, usually make two versions.
	//e.g.  T& front();
	//      const T& front() const;
	T& front() {
		if (empty()) {
			throw std::out_of_range("out of range");
		}
		return _head->_data;
	}
	const T& front() const {
		if (empty()) {
			throw std::out_of_range("out of range");
		}
		return _head->_data;
	}

	T& back() {
		if (empty()) {
			throw std::out_of_range("out of range");
		}
		return _tail->_data;
	}
	const T& back() const {
		if (empty())
		{
			throw std::out_of_range("out of range");
		}
		return _tail->_data;
	}

	//NOTE: if a funct only observes and returns a copy/value, make one const version.
	bool empty() const {
		return _listSize == 0;
	}
	//method to remove from list
};