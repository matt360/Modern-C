#include <iostream>
#include <string>
#include <vector>


int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	int *ptr = arr; //int *ptr = &(arr[0]);

	for (int i = 0; i < sizeof(arr) / sizeof(*ptr); ++i)
	{
		printf("%d\n", *ptr);

		++ptr;
	}

	std::cin.get();
}