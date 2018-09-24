// Created by Mateusz Zaremba

#include <iostream>
#include <string>

void f(float) { std::cout << "float\n"; }
void f(double) { std::cout << "double\n"; }

int main() 
{
	f(2.5);
	f(2.5f);

	std::cin.get();
}