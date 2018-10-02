// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <memory>
#include <vector>


class Widget {};

auto loggingDel = [](Widget *pw)  // custom deleter
{
	auto makeLogEntry = [](Widget *pw) 
	{ 
		std::cout << "logging Del\n"; 
	};
};

std::unique_ptr<Widget, decltype(loggingDel)>  // deleter type is part of ptr type
upw(new Widget, loggingDel);

std::shared_ptr<Widget>                        // deleter type is not part of ptr type
spw(new Widget, loggingDel);

auto customDeleter1 = [](Widget *pw) { std::cout << "customDeleter1"; };  // custom deleters,
auto customDeleter2 = [](Widget *pw) { std::cout << "customDeleter2"; };  // each with a different type

std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
std::shared_ptr<Widget> pw2(new Widget, customDeleter2);

std::vector<std::shared_ptr<Widget>> vpw{ pw1, pw2 };

int main() 
{
	

	std::cin.get();
}