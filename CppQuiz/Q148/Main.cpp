#include <iostream>

volatile int a;

int main() {
	std::cout << (a + a);


	union { int a; int b; };

	
	/*
	The issue here is not the missing initializer of the variable a - it will implicitly be initialized to 0 here. But the issue is the access to a twice without sequencing between the accesses. According to [intro.execution]�4.6�14, accesses of volatile glvalues are side-effects and according to [intro.execution]�4.6�17 these two unsequenced side-effects on the same memory location results in undefined behavior.
	*/
}
