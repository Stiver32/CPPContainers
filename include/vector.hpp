#include <iostream>
template <typename T>
struct mVector
{
	T* _data; // T type pointer to point to address of dynamically allocated data
	size_t _size; // num of elements within
	size_t _capacity; //num of elements that can be held

	mVector() : _size(0), _capacity(3)
	{
		//when vector is created, we want a new array created of type T (allocated at runtime)
		_data = new T[_capacity];

	}
	//initialize vector of given capacity. size is c
	mVector(size_t capacity) : _size(capacity), _capacity(capacity)
	{
		_data = new T[_capacity]();
	}

	//copy constructor
	mVector(const mVector& other)
	{
		_size = other._size;
		_capacity = other._capacity;
		_data = new T[_capacity];
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}

	//copy assignment operator, handle self-assignment(same vector is assigned to itself)
	// release existing memory, then perform a deep copy of the other vector.
	mVector& operator=(const mVector& other)
	{
		if (this == &other) return *this;
		delete[] _data;
		_size = other._size;
		_capacity = other._capacity;
		_data = new T[_capacity];

		for (size_t i = 0; i < _size; ++i)
		{
			_data[i] = other._data[i];
		}

		return *this;
	}


	//avoid deep copies when not needed.
	//move constructor transfers memory ownership from object to object
	mVector(mVector&& other)
	{
		_data = other._data;
		_size = other._size;
		_capacity = other._capacity;
		other._data = nullptr;
		other._size = 0;
		other._capacity = 0;
	}

	//move assignment
	mVector& operator=(mVector&& other)
	{
		if (this == &other) return *this; //check for self assign
		delete[] _data;
		_data = other._data;
		_size = other._size;
		_capacity = other._capacity;
		other._data = nullptr;    // null out original
		other._size = 0;
		other._capacity = 0;
		return *this;
	}


	void resize()
	{
		// create new array with capacity of capacity*2
		_capacity *= 2;
		T* _newData = new T[_capacity]; //temp ptr so dont lose data in _data
		// fill the contents of the new array with the contents of the old array
		for (size_t i = 0; i < _size; i++) {
			_newData[i] = _data[i];
		}
		delete[] _data; // delete old array and assign contents of new array to _data
		_data = _newData;
	}


	//note: different from vector.insert
	void push_back(const T& element)
	{
		// expand capacity
		if (_size == _capacity) {
			resize();
		}
		_data[_size] = element; //add new element to end of container
		_size++; //increment size
	}

	//remove whatever is last in list
	//note: pop_back should prolly DESTROY THE ELEMENT. types with destructors will cause issues
	void pop_back()
	{
		if (_size > 0)
			_size--;
	}



	size_t getSize() const{
		return _size;
	}
	size_t getCapacity() const{
		return _capacity;
	}

	//overload [] operator for random access functionality
	T& operator[](size_t index){
		if (index >= _size){
			throw std::out_of_range("index out of bounds");
		}
		return _data[index];
	}

	// T* const means a const pointer(the pointer itself can't be reassigned)
	// const T* (pointer to const data — can't modify what it points to)
	// the method itself needs to be marked const too:
		//The const after the parentheses marks the method as callable on a const object —
		// without it the compiler can't distinguish which version to call.
	//return ptr to first element
	T* begin() { return _data; }
	const T* begin() const { return _data; }

	//return ptr to ending element
	T* end() { return _data + _size; }
	const T* end() const { return _data + _size; }

	T& front()
	{
		return *begin();
	}

	const T& front() const
	{
		return *begin();
	}

	~mVector(){
		delete[] _data;
	}


};