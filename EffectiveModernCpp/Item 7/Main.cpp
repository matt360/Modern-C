#include <iostream>
#include <string>
#include <vector>



int main()
{
	int x(0);              // initializer is in parentheses

	int y = 0;             // initializer follows "=" (assignment)

	int z{ 0 };            // initializer is in braces

	int z = { 0 };         // initializer uses "=" and braces. C++ usally treats it the same as the braces-only version.


	std::cin.get();
}