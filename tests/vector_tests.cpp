#include "../vector.cpp"
#include <iostream>

int main()
{
	mVector<int> v1;
	mVector<int> v2;
	std::cout << v1._size << "\n";
	std::cout << v1._size << "\n";
	std::cout << v2._capacity << "\n";
	std::cout << v2._capacity << "\n";
}