#include <iostream>

// C++14
template <typename T, T value> T f()
{
	return value * 2;
}


int main()
{
	auto i = f<int, 10>();

	std::cout << i << std::endl;

	std::cin.get();
}