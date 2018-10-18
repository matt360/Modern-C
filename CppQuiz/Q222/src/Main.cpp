// Created by Mateusz Zaremba

#include <iostream>
#include <variant>


using namespace std;

int main() 
{
	variant<int, double, char> v;
	cout << v.index();

	std::cin.get();
}