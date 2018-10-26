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

template<typename... Ts>
std::unique_ptr<Investment>
makeInvestment(Ts&&... params)
{
	// custom deleter (as stateless lambda expression)
	auto delInvmt = [](Investment* pInvestment)   // this is now inside makeInvestment
	{                                             // 
		makeLogEntry(pInvestment);                // 
		delete pInvestment;
	};

	std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
		pInv(nullptr, delInvmt);                         // returned

	// 1, 0, 0 in 'if' and 'else if' statements is just for testing
	if (1 /* a Stock object should be created */)
	{
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if (0 /* a Bond object should be created */)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if (0 /* a RealEstate object should be created */)
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}

	return pInv;
}

void delInvmt2(Investment* pInvestment)  // custom
{                                        // deleter
	makeLogEntry(pInvestment);           // as function
	delete pInvestment;
}

template<typename... Ts>                 // return type has
std::unique_ptr<Investment>              // size of Investment*
makeInvestment2(Ts&&... params, void (*)(Investment*))          // plus at least size of function pointer!
{
	// custom deleter (as stateless lambda expression)
	auto delInvmt = [](Investment* pInvestment)   // this is now inside makeInvestment
	{                                             // 
		makeLogEntry(pInvestment);                // 
		delete pInvestment;
	};

	std::unique_ptr<Investment, decltype(delInvmt)>      // ptr to be
		pInv(nullptr, delInvmt);                         // returned

	if (1 /* a Stock object should be created */)
	{
		pInv.reset(new Stock(std::forward<Ts>(params)...));
	}
	else if (0 /* a Bond object should be created */)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if (0 /* a RealEstate object should be created */)
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
	
	std::shared_ptr<Investment> sp = makeInvestment(); 

	std::cin.get();
}
