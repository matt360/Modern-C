#include <iostream>

const char name[] = "J.P. Briggs";
const char * ptrToName = name;

template<typename T>
void f(T param) {
};

int main()
{
	f(name);

	return 0;
}