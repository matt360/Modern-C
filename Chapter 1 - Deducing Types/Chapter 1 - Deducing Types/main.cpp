#include <iostream>
#include <array>

const char name[] = "J.P. Briggs";
const char * ptrToName = name;

template<typename T>
void f(T param) {};

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept  // as for arraySize being declared nonexcept, 
{                                                  // that's to help compilers generate better code.
	return N;
}

int main()
{
	f(name);

	int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };     // keyVals has 7 elements

	int mappedVals[arraySize(keyVals)];             // so does mappedVals

	std::array<int, arraySize(keyVals)> mappedVals; // mappedVals' size is 7

	return 0;
}