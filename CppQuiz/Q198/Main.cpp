#include <iostream>
#include <string>
#include <vector>

namespace A {
	  int x; 
};

namespace B {
	  int x; 
};


int main()
{
	std::cout << B::x;
	
	std::cout << B::x;

	std::cin.get();
}