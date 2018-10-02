// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Investment {};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};

template<typename... Ts>       // return std::unique_ptr
std::unique_ptr<Investment>    // to an object created
makeInvestment(Ts&&... params) // from the given args
{
	std::unique_ptr<Investment> u;
	return u;
};

int main() 
{
	{
		auto pInvestment =     // pInvestment is of type
			makeInvestment();  // std::unique_ptr<Investment>
							   
	}                          // destroy *pInvestment

	std::shared_ptr<Investment> sp = // converts std::unique_ptr
		makeInvestment();            // to std::shared_ptr

	std::cin.get();
}