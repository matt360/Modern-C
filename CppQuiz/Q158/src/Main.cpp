// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <vector>

struct Foo
{
	Foo() { std::cout << "a"; }
	Foo(const Foo&) { std::cout << "b"; }
};

int main() 
{
	std::vector<Foo> bar(5);

	// output:
	// aaaaa

	std::cin.get();
}