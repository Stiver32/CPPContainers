#include "../vector.cpp"
#include <iostream>

int main()
{
	mVector<int> v1;
	mVector<int> v2;
	std::cout << v1._size << "\n";
	v1.push_back(64);
	std::cout << v1._size << "\n";
	v1.push_back(62);
	std::cout << v1._size << "\n";


}