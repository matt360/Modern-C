// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <memory>


class Widget {};

auto loggingDel = [](Widget *pw)
{
	auto makeLogEntry = [](Widget *pw) 
	{ 
		std::cout << "logging Del\n"; 
	};
};


int main() 
{
	

	std::cin.get();
}