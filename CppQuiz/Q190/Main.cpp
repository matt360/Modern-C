#include <iostream>
#include <string>
#include <vector>


struct A {
	A(int i) : i(i) {}
	operator bool() const { return i > 0; }
	int i;
};

int main()
{
	A a1(1), a2(2);
	std::cout << a1 + a2 << (a1 == a2);

	std::cin.get();
}