#include <iostream>
#include <string>
#include <vector>

/*
class Empty
{

};

// after writing just this the compiler will automatically define it's own version of:
// - copy constructor
// - copy assignment operator
// - destructor
// so it will looks like this:
*/

class Empty
{
public:
	Empty() {}                               // default constrctor
	Empty(const Empty& rhs) {}               // default copy constructor
	~Empty() {}                              // default destructor

	// Have assignment operators return a reference to *this
	Empty& operator=(const Empty&rhs)        // default assignment operator; return type is a reference to the current class
	{
		return *this;                        // return the left-hand object
	}

	Empty& operator+=(const Empty& rhs)      // the convenction applies to: +=, -=, *= etc.
	{
		return *this;
	}

	Empty& operator=(int rhs)                 // it applies even if the operator's parameter type is unconventional
	{
		return *this;
	}

private:
	// declare the copy constructor and the assignment operator yourself to prevent the compiler from creating its own
 	// and declare them private so the user can't use them.
	Empty(const Empty& rhs) {}
	Empty& operator=(const Empty&rhs)
	{
		return *this;                        // return the left-hand object
	}
};

int main()
{
	Empty e1;

	Empty e2(e1);
	e2 = e1;

	std::cin.get();
}