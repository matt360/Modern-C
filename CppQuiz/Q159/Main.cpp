#include <iostream>

int i;

void f(int x)
{
	std::cout << x << i;
}

int main()
{
	i = 3;
	f(i++);

	// output:
	// 34

	/*
	According to [intro.execution]�4.6�18 in the standard, when calling a function, every value computation and side effect associated with any argument expression, is sequenced before the function is entered. Hence, in the expression f(i++), f is called with a parameter of the original value of i, but i is incremented before entering the body of f.
	*/

	std::cin.get();
}
