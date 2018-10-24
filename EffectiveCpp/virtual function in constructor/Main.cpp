#include <iostream>
#include <string>
#include <vector>

/*
make sure that
none of your constructors or destructors call virtual functions on the
object being created or destroyed and that all the functions they call
obey the same constraint.
*/

class Transaction {							   // base class for all transactions
public:
	Transaction();
	virtual void logTransaction() const {      // make type-dependent log entry
		std::cout << "Transaction" << std::endl;
	};
	void init() {
		logTransaction();                      // as final action, log this transaction
	};

	// ...

};

Transaction::Transaction()		               // implementation of base class actor
{
	// ...
	init();
}

class BuyTransaction : public Transaction {            // derived class
public:
	virtual void logTransaction() const {
		std::cout << "BuyTransaction" << std::endl;    // how to log transactions of this type
	};
	// ...
};

class SellTransaction : public Transaction {   // derived class
public:
	virtual void logTransaction() const {
		std::cout << "SellTransaction" << std::endl; // how to log transactions of this type
	};
	// ...
};

int main()
{
	BuyTransaction b;


	std::cin.get();
}