// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct X 
{
	X() { std::cout << "1"; }
	X(const X &) { std::cout << "3"; }
	~X() { std::cout << "2"; }

	void f() { std::cout << "4"; }

} object;

int main() 
{
	{
		X(object);
		object.f();
	}
	std::cin.get();
}