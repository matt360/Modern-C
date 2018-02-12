// The Cherno Project - How The C++ Compiler Works https://www.youtube.com/watch?v=3tIqpEmWMLI&index=6&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// 

#include <iostream>

void Log(const char* message);

int main()
{
	Log("Hello World!");

	std::cin.get();
}