#include <iostream>

int main()
{
	const std::string myString = "My Hello World Wow";

	// C++17
	if (const auto it = myString.find(" "); it != std::string::npos)
		std::cout << "Found a space on the " << it << "th place" << std::endl;
	else
		std::cout << "Space not found!" << std::endl;

	// C++
	const auto it = myString.find_last_of(" ");
	if (it != std::string::npos)
		std::cout << "Last space found! Index number: " << it << std::endl;
	else
		std::cout << "Space not found!" << std::endl;

	// C++ 17
	if (const auto it = myString.find_first_of(" "); it != std::string:npos)
		std::cout << "First space found! Index number: " << it << std::endl;

	std::cin.get();
}