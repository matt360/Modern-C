// Created by Mateusz Zaremba

#include <iostream>
#include <string>

void f()
{
	std::cout << "1";
}

template<typename T>
struct B
{
	void f()
	{
		std::cout << "2";
	}
};

template<typename T>
struct D : B<T>
{
	void g()
	{
		f();
	}
};

int main() 
{
	D<int> d;
	d.g();

	// output:
	// 1

	/*
	According to the standard, [temp.dep]§17.6.2¶3, "in the definition of a class or class template, if a base class depends on a template-parameter, the base class scope is not examined during unqualified name lookup either at the point of definition of the class template or member or during an instantiation of the class template or member". So when the compiler sees a call to a function f() inside g() it should choose the one from the global scope, and the program should output "1". See discussions in the C++ FAQ and on Stack Overflow.

	In the real life, not all compilers obey this section of the standard, and some of them produce (erroneously) the code that outputs "2". For example, GCC 4.9.3 - "1", Clang 3.8.1 - "1", Microsoft C++ 19.00.24210 - "2", Intel C++ 15.0.7.287 - "2". Even if the implementation you use calls B::f() for the unqualified f(), you should not rely on this behaviour.
	*/

	std::cin.get();
}