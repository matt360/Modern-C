#include <iostream>
#include <string>
#include <vector>


void logCall(const std::string& funcName) // make a log entry
{
	std::cout << funcName << '\n';
}

class Date { };

class Customer {
public:

	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);

private:
	std::string name;
	Date lastTransaction;
};

Customer::Customer(const Customer& rhs)
	: name(rhs.name) // copy rhs’s data
{
	logCall("Customer copy constructor");
}
Customer& Customer::operator=(const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	name = rhs.name; // copy rhs’s data
	return *this; // see Item 10
}

class PriorityCustomer : public Customer { // a derived class
public:
	PriorityCustomer(const PriorityCustomer& rhs);
	PriorityCustomer& operator=(const PriorityCustomer& rhs);

private:
	int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
	: Customer(rhs), // invoke base class copy ctor
	priority(rhs.priority)
{
	logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
	logCall("PriorityCustomer copy assignment operator");
	Customer::operator=(rhs); // assign base class parts
	priority = rhs.priority;
	return *this;
}

int main()
{
	// Things to Remember
	// ✦ Copying functions should be sure to copy all of an object’s data
	// members and all of its base class parts.
	// ✦ Don’t try to implement one of the copying functions in terms of the
	// other.Instead, put common functionality in a third function that
	// both call.

	std::cin.get();
}