// FUNCTION POINTERS

// Function pointers are a way to assign a functino to a variable
// Functions are just CPU instructions.

#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorld(int a)
{
	std::cout << "Hello World! Value: " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	// return_type(*name)(parameters)
	void(*charno)() = &HelloWorld; // getting the function pointer, the memory address of that function
	//charno = HelloWorld;
	charno();
	charno();

	typedef void(*HelloWorldFunction)();
	HelloWorldFunction function = HelloWorld;
	function();
	function();

	typedef void(*HelloWorldFunctionParam)(int);
	HelloWorldFunctionParam function_param = HelloWorld;
	function_param(2);
	function_param(2);

	void(*HW)(int) = &HelloWorld;
	HW(1);

	typedef void(*HWO)(int);
	HWO hello_world = HelloWorld;
	hello_world(3);

	// Example 1
	std::vector<int> values = { 1, 5, 4, 2, 3 };
	ForEach(values, PrintValue);

	// Example 2 - lambda
	ForEach(values, [](int value){ std::cout << "Lambda Value: " << value << std::endl; });

	std::cin.get();
}
