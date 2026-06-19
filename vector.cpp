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
	
	void resize()
	{
		// create new array with capacity of capacity*2
		T* _newData = new T[_capacity * 2]; //temp ptr so dont lose data in _data
		// fill the contents of the new array with the contents of the old array
		for (size_t i : size){
			_newData[i] = _data[i];
		}
		delete[] _data; // delete old array and assign contents of new array to _data
		_data = _newData;
	}
		

	//note: different from vector.insert
	void push_back(const T &element)
	{
		// expand capacity
		if (_size == _capacity) {
			resize();
		}
		_data[_size] = element; //add new element to end of container
		size_++; //increment size
	}



	~mVector()
	{
		delete[] _data;
	}
	

};