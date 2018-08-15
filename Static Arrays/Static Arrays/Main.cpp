#include <iostream>
#include <array>


// Arrays are always stored on the stack
// Use std::array instead of C-syled array because
// it doesn't have any overhead compared to the C-style array


// C-style
void PrintArray(const int* array, unsigned int size)
{

}

void PrintArray(const std::array<int, 5>& array)
{

}

int main()
{
	// std::array
	std::array<int, 5> data;
	data[0] = 2;
	data[1] = 1;
	data.size();

	// C-style array
	int dataOld[5];
	dataOld[0] = 2;
	dataOld[1] = 1;



	std::cin.get();
}