#include <iostream>

const char name[] = "J.P. Briggs";
const char * ptrToName = name;

template<typename T>
void f(T param) {
};

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept
{
	return N;
}

int main()
{
	f(name);

	return 0;
}