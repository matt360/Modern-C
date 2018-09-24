// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct A {
	A() { std::cout << "A"; }
	A(const A &a) { std::cout << "B"; }
	virtual void f() { std::cout << "C"; }
};

int main() 
{
	{
		A a[2];
		for (auto x : a) {
			x.f();
		}
	}

	std::cin.get();
}