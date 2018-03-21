#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;
};

int main()
{
	int offset_x = (int)&((Vector3*)0)->x;
	int offset_y = (int)&((Vector3*)NULL)->y;
	int offset_z = (int)&((Vector3*)nullptr)->z;
	std::cout << offset_x << std::endl;
	std::cout << offset_y << std::endl;
	std::cout << offset_z << std::endl;

	std::cin.get();

	return (int)&((Vector3*)0)->x;
}