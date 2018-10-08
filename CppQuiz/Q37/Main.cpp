#include <iostream>
#include <string>
#include <vector>

int main()
{
	int a = 0;
	decltype(a) b = a;
	b++;
	std::cout << a << b;

	// output:
	// 01

	/*
	According to [dcl.type.simple]§10.1.7.2¶4 in the C++ standard:
	"The type denoted by decltype(e) is deﬁned as follows:
	— if e is an unparenthesized id-expression [...], decltype(e) is the type of the entity named by e."

	The type of a is int, so the type of b is also int.
	*/
	
	std::cin.get();
}