#include <iostream>
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

class VECTOR3D
{
public:
	// operations, etc...

	union
	{
		float m[3];

		struct
		{
			float x, y, z;
		};
	};
};



int main()
{
	VECTOR3D v;
	// same effect
	v.m[0] = 1.0f;
	v.x = 1.0f;



	std::cin.get();
}