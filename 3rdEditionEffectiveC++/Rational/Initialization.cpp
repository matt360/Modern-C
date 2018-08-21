#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


class PhoneNumber { };
class ABEntry { // ABEntry = “Address Book Entry”
public:
	ABEntry(const std::string& name, const std::string& address,
		const std::list<PhoneNumber>& phones);
private:
	/*
	Initialization took place earlier —
	when their default constructors were automatically called
	prior to entering the body of the ABEntry constructor.
	*/
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	/*
	This isn’t true for
	numTimesConsulted, because it’s a built-in type. For it, there’s no guarantee
	it was initialized at all prior to its assignment.
	*/
	int numTimesConsulted;
};

ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
{
	theName = name; // these are all assignments,
	theAddress = address; // not initializations
	thePhones = phones;
	numTimesConsulted = 0;
}

/*
A better way to write the ABEntry constructor is to use the member initialization
list instead of assignments:
*/
ABEntry::ABEntry(const std::string& name, const std::string& address,
	const std::list<PhoneNumber>& phones)
	:theName(name),
	 theAddress(address), // these are now all initializations
	 thePhones(phones),
	 numTimesConsulted(0) // For objects of built-in type like numTimesConsulted, there is no difference
						  // in cost between initialization and assignment, but for consistency,
						  // it’s often best to initialize everything via member initialization.
{} // the ctor body is now empty

/*
Similarly, you can use the member initialization list even when you
want to default-construct a data member; just specify nothing as an
initialization argument. For example, if ABEntry had a constructor taking
no parameters, it could be implemented like this:
*/
ABEntry::ABEntry()
	:theName(),				// call theName’s default ctor;
	 theAddress(),			// do the same for theAddress;
	 thePhones(),			// and for thePhones;
	 numTimesConsulted(0)	// but explicitly initialize
{}