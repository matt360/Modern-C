// C++17
/*
- Template deduction of constructors, allowing std::pair(5.0, false) instead of std::pair<double,bool>(5.0, false)
- 
*/

#include <tuple>
#include <iostream>
#include <string>

std::tuple<int, std::string> returnMultipleValues()
{
	//return std::make_tuple(1, "Soni", 2.4, 'a'); // Always works
	return { 1, "Soni" }; // C++ 17
}

std::tuple<int, bool, float> foo()
{
	return { 128, true, 1.5f };
}

int main()
{
	int i;
	std::string s;

	auto [i, s] = returnMultipleValues();

	std::cout << "i " << i;

	std::tuple<int, bool, float> result = foo();
	int value = std::get<0>(result);
	auto[value1, value2, value3] = foo();

	std::cin.get();
}