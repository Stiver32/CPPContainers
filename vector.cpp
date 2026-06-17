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
	

	~mVector()
	{
		delete[] _data;
	}
	

};