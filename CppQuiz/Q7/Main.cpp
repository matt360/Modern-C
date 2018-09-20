#include <iostream>
#include <string>
#include <vector>

class A {
public:
	void f() { std::cout << "A"; }
};

class B : public A {
public:
	void f() { std::cout << "B"; }
};

void g(A& a) { a.f(); }

int main()
{
	B b;
	g(b);

	std::cin.get();
}