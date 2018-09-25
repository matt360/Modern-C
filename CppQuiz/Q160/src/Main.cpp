// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct A
{
	virtual void foo(int a = 1)
	{
		std::cout << "A" << a;
	}
};

struct B : A
{
	virtual void foo(int a = 2)
	{
		std::cout << "B" << a;
	}
};

int main() 
{
	A* b = new B;
	b->foo();

	// outout:
	// B1

	/*
	[dcl.fct.default]§11.3.6¶10 in the standard:
	A virtual function call (§13.3) uses the default arguments in the declaration of the virtual function determined by the static type of the pointer or reference denoting the object. An overriding function in a derived class does not acquire default arguments from the function it overrides.

	Thus, an overridden function foo() will be called with argument int a = 1, and the output is B1.
	*/

	std::cin.get();
}