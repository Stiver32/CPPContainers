#include <iostream>

template<typename T>
class LinkedList {
private:
	struct Node {
		Node* _next;
		T _data;
		Node(const T& data) : _next(nullptr), _data(data) {}
	};
public:

	Node* _head; 
	Node* _tail; 
	std::size_t _listSize;

	// Default constructor
	LinkedList() : _tail(nullptr), _head(nullptr), _listSize(0) {}


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
	void push_front(const T& value){
		Node* newNode = new Node(value); // note: (*newNode).next = _head
		newNode->_next = _head; // Set newnode's next to be _head
		_head = newNode; // Set _head to newnode

		if (_tail == nullptr) {
			_tail = newNode;
		}
		++_listSize;
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
		Node* curr = _head;
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

	// Method returns list size
	std::size_t size() const{
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

	~LinkedList();
};