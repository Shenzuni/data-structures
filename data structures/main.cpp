#include "array.cpp"

#include <iostream>

int main() {	
	array<array<int, 2>, 3> array1 = { 1, 3, 2, 3, 4, 3 };

	array<array<int, 2>, 3> array2 = { 9, 9, 9, 9, 9, 9 };

	array1.fill({4, 4});
	std::cout << array1.at(2) << std::endl;
	std::cout << array1.back() << std::endl;
	std::cout << array1.data() << std::endl;
	std::cout << array1.empty() << std::endl;
	array2.fill({3, 2});
	std::cout << array1.max_size() << std::endl;
	std::cout << array1.size() << std::endl;
	array1.swap(array2);
	std::cout << array1._data << std::endl;
}