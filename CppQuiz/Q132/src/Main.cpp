// Created by Mateusz Zaremba

#include <iostream>
#include <string>

using namespace std;

int foo()
{
	cout << 1;
	return 1;
}

void bar(int i = foo()) {}

int main() 
{
	bar();
	bar();

	// output:
	// 11

	/*
	Is foo called both times or just once? The C++ standard says this in [dcl.fct.default]§11.3.6¶9: 
	"A default argument is evaluated each time the function is called with no argument for the corresponding parameter."

	Thus, foo is called twice.
	*/

	std::cin.get();
}