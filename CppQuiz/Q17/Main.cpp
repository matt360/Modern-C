#include <iostream>
#include <string>
#include <vector>

class A {
public:
	A() { std::cout << 'A'; }
	~A() { std::cout << 'a'; }

	//virtual void foo() = 0;
};

class B : public A {
public:
	B() { std::cout << 'B'; }
	~B() { std::cout << 'b'; }

	//virtual void foo() override {} ;
};

int main()
{
	{
		A a;
	}
	std::cout << '\n';
	{
		B b;
	}
	std::cout << '\n';
	{
		A a;
		B b;
	}

	std::cin.get();
}