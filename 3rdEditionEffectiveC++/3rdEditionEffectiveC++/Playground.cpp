#include <iostream>
#include <string>
#include <vector>

class Investment { public: bool b : 1; }; // root class of hierarchy of investment types

Investment* createInvestment(); // return ptr to dynamically allocated
                                // object in the Investment hierarchy;
                                // the caller must delete it
                                // (parameters omitted for simplicity)

int main()
{
	Investment i{};	

	std::cout << i.b;

	std::cin.get();
}