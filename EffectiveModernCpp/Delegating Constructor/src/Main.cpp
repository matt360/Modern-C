// Created by Mateusz Zaremba

#include <iostream>
#include <string>

// source http://www.learncpp.com/cpp-tutorial/b-5-delegating-constructors/

class Foo
{
public:
	Foo()
	{
		// code to do A
		std::cout << "A";
	}

	Foo(int Value) : Foo() // use Foo() default constructor to do A
	{
		// code to do B
		std::cout << "B";
	}
};

int main() 
{
	{
		Foo f;
	}
	std::cout << '\n';
	{
		Foo f(1);
	}

	std::cin.get();
}