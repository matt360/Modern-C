#include <iostream>
#include <map>

int main()
{
	std::map<char, int> myMap = { {'1', 1}, {'2', 1}, {'3', 3} };

	// C++17
	for (const auto& [k, v] : myMap)
	{
		std::cout << "key: " << k << " value: " << v << std::endl;
	}

	std::cin.get();
}