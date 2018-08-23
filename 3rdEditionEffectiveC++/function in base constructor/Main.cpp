#include <iostream>
#include <string>
#include <vector>

/*
make sure that
none of your constructors or destructors call virtual functions on the
object being created or destroyed and that all the functions they call
obey the same constraint.
*/

class Transaction {							           // base class for all transactions
public:
	explicit Transaction(const std::string& logInfo);
	void logTransaction(const std::string& logInfo) const {
		std::cout << "\nTransaction 'logTransaction' logInfo: " << logInfo << std::endl;
	};
};

Transaction::Transaction(const std::string& logInfo)		                       // implementation of base class actor
{
	std::cout << "\nTransaction constructor called!\n";
	logTransaction(logInfo);
}

class BuyTransaction : public Transaction {            // derived class
public:
	BuyTransaction(const std::string& logInfo) :
		Transaction(createLogString(logInfo)) {
		std::cout << "\nBuyTransaction constructor called!\n";
	}

private:
	static std::string staticLogInfo;
	static const std::string& createLogString(const std::string& logInfo) {
		staticLogInfo = logInfo;
		return staticLogInfo;
	};
};

std::string BuyTransaction::staticLogInfo = "";

class SellTransaction : public Transaction {           // derived class
public:
	SellTransaction(const std::string& logInfo) :
		Transaction(logInfo) {
		std::cout << "\nSellTransaction constructor called!\n";
	}


private:
	static std::string staticLogInfo;
	static const std::string& createLogString(const std::string& logInfo) {
		staticLogInfo = logInfo;
		return staticLogInfo;
	};
};

int main()
{
	BuyTransaction b("BuyTransaction");
	SellTransaction s("SellTransaction");

	std::cin.get();
}