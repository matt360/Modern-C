// Created by Mateusz Zaremba

#include <iostream>
#include <string>

/*
[expr.sub]§8.2.1¶1 in the standard says "The expression E1[E2] is identical (by definition) to *((E1)+(E2))".

In our case 1["ABC"] is identical to *(1 + "ABC").Since the plus operator is commutative, this is identical to *("ABC" + 1), which is identical to the more familiar "ABC"[1].
*/

int main() 
{
	std::cout << 1["ABC"];
	std::cout << "ABC"[1];
	std::cout << *(1 + "ABC");
	std::cout << *("ABC" + 1);

	std::cin.get();
}