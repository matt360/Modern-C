// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
/*
	[stmt.cont]§9.6.2¶1 in the standard: 
	"The continue statement (...) causes control to pass to the loop-continuation portion of the smallest enclosing iteration-statement, that is, to the end of the loop." (Not to the beginning.)
*/
	int i = 1;
	do {
		std::cout << i;
		i++;
		if (i < 3) continue;
	} while (false);

	std::cin.get();
}