
#include <iostream>
template<typename T>
class LinkedList {
private:
	struct Node {
		Node* _next;
		T _data;
		
		Node(const T& data) : _next(nullptr), _data(data) {}
	};

	/*    **DATA MEMBERS**   */

	Node* _head;
	Node* _tail;
	size_t _listSize;

public:


	/*    **CONSTRUCTORS**    */

	// Default constructor
	LinkedList() : _tail(nullptr), _head(nullptr), _listSize(0) {}

	// Constructor with size param
	LinkedList(size_t size)
	{
		_listSize = 0;
		_tail = nullptr;
		_head = nullptr;
		for(std::size_t i = 0; i < size; i++) //size_t is unsigned int, use std::size_t to avoid warnings when comparing with signed int
		{
			push_back(T{}); //default value of T
		}
	}

	// Copy Constructor
	LinkedList(const LinkedList& other)
	{
		//need new list with same values in same order. but separate node objects
		_tail = nullptr;
		_head = nullptr;
		_listSize = 0;

		Node* curr = other._head;
		while (curr != nullptr)
		{
			push_back(curr->_data);
			curr = curr->_next;
		}
	}

	////Copy Assignment Operator
	LinkedList& operator=(const LinkedList& other)
	{
		if (this == &other) return *this; // handle self-assignment case
		clear(); //clear list
		// copy nodes from other list to this list
		Node* curr = other._head;

		while (curr != nullptr)
		{
			push_back(curr->_data); //add node to back of list
			curr = curr->_next;
		}
		return *this; //return current object
	}



	// Move Constructor
	LinkedList(LinkedList&& other) noexcept
	{
		_head = other._head; 
		_tail = other._tail;
		_listSize = other._listSize;
		other._head = nullptr; 
		other._tail = nullptr;
		other._listSize = 0;
	}
	


	//Move Assignment Operator
	LinkedList& operator=(LinkedList&& other) noexcept
	{
		if (this == &other) return *this; //handle self-assignment
		clear(); //clear current list
		_head = other._head; 
		_tail = other._tail; 
		_listSize = other._listSize;
		other._head = nullptr; 
		other._tail = nullptr; 
		other._listSize = 0;
		return *this;
	} 

	/*    ** MEMBER FUNCTIONS **    */

	// Method to add to list (to back)
	void push_back(const T& value) {
		Node* newNode = new Node(value);
		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
		}
		else {
			_tail->_next = newNode; //whatever's at current list tail, make next point to added node
			_tail = newNode; //set tail to added node
		}
		++_listSize;
	}

	// Method to add to list (from front)
	void push_front(const T& value) {
		Node* newNode = new Node(value); // note: (*newNode).next = _head
		newNode->_next = _head; // Set newnode's next to be _head
		_head = newNode; // Set _head to newnode

		if (_tail == nullptr) {
			_tail = newNode;
		}
		++_listSize;
	}

	//remove whatever is last in list
	void pop_back(){
		if (empty()){
			throw std::out_of_range("List is empty");
		}

		//if only one node in list
		if (_head == _tail){
			delete _head;
			_head = nullptr;
			_tail = nullptr;
			_listSize = 0;
			return;
		}

		Node* curr = _head;
		while (curr->_next != _tail){
			curr = curr->_next;
		}
		delete _tail;

		_tail = curr;
		_tail->_next = nullptr;

		--_listSize;

	}

	T& get(size_t index) {
		if (index >= _listSize) {
			throw std::out_of_range("index out of range");
		}
		// Set new current node to beginning of list (head)
		Node* curr = _head;
		// Iterate thru list while index < i(0). When index !< i, move current ptr forward by one
		for (std::size_t i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		return curr->_data;
	}

	// Const get() so method is callable on const obj
	const T& get(size_t index)const {
		if (index >= _listSize) {
			throw std::out_of_range("index out of range");
		}
		const Node* curr = _head;
		for (std::size_t i = 0; i < index; ++i) {
			curr = curr->_next;
		}
		return curr->_data;
	}


	// Get element at front method
	T& front() {
		if (empty()) {
			throw std::out_of_range("out of range");
		}
		return _head->_data;
	}
	//NOTE: If the function observes but returns access to internal data, usually make two versions.
		//e.g.  T& front();
		//      const T& front() const;
	const T& front() const {
		if (empty()) {
			throw std::out_of_range("out of range");
		}
		return _head->_data;
	}


	// Get element at back method
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

	//return ending element
	

	// Method returns list size
	std::size_t size() const {
		return _listSize;
	}

	// Method to check if list is empty
	// NOTE: if a funct only observes and returns a copy/value, make one const version.
	bool empty() const {
		return _listSize == 0;
	}

	// Method to clear list 
	void clear() {
		//set curr to head
		Node* curr = _head;
		//wehile curr != nullptr
		while (curr != nullptr) {
			Node* temp = curr->_next;
			delete curr; //release memory at curr
			curr = temp;
		}
		// set stack memory to null
		_head = nullptr;
		_tail = nullptr;
		_listSize = 0;
	}

	// Remove element at index
	void RemoveAt(std::size_t index)
	{
		if (index >= _listSize){
			throw std::out_of_range("Index out of range");
		}
		// Remove head
		if (index == 0){
			Node* oldHead = _head;
			_head = _head->_next;

			delete oldHead;
			--_listSize;
			if (_listSize == 0){
				_tail = nullptr;
			}
			return;
		}

		Node* curr = _head;
		// Move to node immediately before index
		for (std::size_t i = 0; i < index - 1; ++i){
			curr = curr->_next;
		}

		Node* nodeToDelete = curr->_next;
		curr->_next = nodeToDelete->_next;

		if (nodeToDelete == _tail){
			_tail = curr;
		}

		delete nodeToDelete;
		--_listSize;
	}


	~LinkedList(){
		clear();
	}
};