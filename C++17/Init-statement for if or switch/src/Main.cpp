#include <iostream>

int main()
{
	const std::string myString = "My Hello World Wow";

	if (const auto it = myString.find("World"); it != std::string::npos)
		std::cout << "World found on the " << it << "th position" << std::endl;
	else
		std::cout << "Nothing found!" << std::endl;

	std::cin.get();
}