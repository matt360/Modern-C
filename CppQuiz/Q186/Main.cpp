#include <iostream>
#include <typeinfo>

void takes_pointer(int* pointer) {
	if (typeid)(pointer) == typeid(int[])) std::cout << 'a';
	if (typeid)(pointer) == typeid(int*)) std::cout << 'b';
}

void takes_array(int array[]) {
	if (typeid(array) == typeid(int[])) std::cout << 'a';
	if (typeid(array) == typeid(int*)) std::cout << 'p';
}

int main()
{
	

	std::cin.get();
}
