#include <iostream>
#include <variant>

// source code: https://www.bfilipek.com/2018/06/variant.html

union SuperFloat
{
	float f;
	int i;
};

int RawMantissa(SuperFloat f)
{
	return f.i & ((1 << 23) - 1);
};

int RawExponent(SuperFloat f)
{
	return (f.i >> 23) & 0xFF;
}

int main()
{
	

	std::cin.get();
}