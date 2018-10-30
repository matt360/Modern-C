// Created by Mateusz Zaremba

#include <iostream>
#include <string>

template <typename ...Ts>
struct X 
{
	X(Ts ...args) : Var(0, args...) {}
	int Var;
};

int main() 
{
	X<> x;

	std::cin.get();
}