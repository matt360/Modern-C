#include <iostream>
#include <string>
#include <vector>

class Transaction {							   // base class for all transactions
public:
	Transaction();
	virtual void logTransaction() const = 0;   // make type-dependent log entry

	// ...

};

Transaction::Transaction()		               // implementation of base class actor
{
	// ...
	logTransaction();                          // as final action, log this transaction
}

class BuyTransaction : public Transaction {    // derived class
public:
	virtual void logTransaction() const;       // how to log transactions of this type
	// ...
};

class SellTransaction : public Transaction {   // derived class
public:
	virtual void logTransaction() const;       // how to log transactions of this type
	// ...
};

int main()
{
	BuyTransaction b;


	std::cin.get();
}