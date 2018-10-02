// Created by Mateusz Zaremba

#include <iostream>
#include <string>

class Investment {
public:
	virtual ~Investment() {}                  // essential design component!
};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};


void makeLogEntry(Investment* pInvestment)
{
	std::cout << "Investment destroyed!" << std::endl;
};

auto delInvmt = [](Investment* pInvestment)   // custom
{                                             // deleter
	makeLogEntry(pInvestment);                // (as stateless lambda
	delete pInvestment;                       // expression)
};

template<typename... Ts>                         // return type
std::unique_ptr<Investment, decltype(delInvmt)>  // has size of
makeInvestment(Ts&&... params)                   // Investment*
{
	std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
	pInv(nullptr, delInvmt);                         // returned

	if ( 1 /* a Stock object should be created */ )
	{
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if ( 0 /* a Bond object should be created */ )
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if ( 0 /* a RealEstate object should be created */ )
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}

	return pInv;
}

int main() 
{
	{
		makeInvestment();
	}

	std::cin.get();
}