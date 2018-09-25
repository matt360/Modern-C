// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <vector>

int f() { std::cout << "f"; return 0; }
int g() { std::cout << "g"; return 0; }

void h(std::vector<int> v) {}

int main() 
{
	h({f(), g()});

	// output:
	// fg

	/*
	The goal of this question is to demonstrate that the evaluation order of elements in an initializer list is specified (as opposed to the arguments to a function call).

	[dcl.init.list]�11.6.4�4: Within the initializer-list of a braced-init-list, the initializer-clauses, including any that result from pack expansions (�17.5.3), are evaluated in the order in which they appear.

	If h took two ints instead of a vector<int>, and was called like this:
	h(f(), g());
	the program would be unspecified, and could either print fg or gf.
	*/

	std::cin.get();
}