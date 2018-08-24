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

class Uncopyable
{
protected:
	Uncopyable() {}
	~Uncopyable() {}
private:
	// copy constructor
	Uncopyable(const Uncopyable&);
	// assignment operator
	Uncopyable operator=(const Uncopyable&);
};

class Empty : private Uncopyable
{
public:
	Empty() {}                               // default constrctor
	//Empty(const Empty& rhs) {}               // default copy constructor
	~Empty() {}                              // default destructor

	// Have assignment operators return a reference to *this
	//Empty& operator=(const Empty&rhs)        // default assignment operator; return type is a reference to the current class
	//{
	//	return *this;                        // return the left-hand object
	//}

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
	// and declare them private so the user can't use them and don't define them so even friend or member functions
	// can't call them (a common convention in such case is to ommit the names of the functions' parameters.
	// Using a base class like Uncopyable is one way to do this.
	//Empty(const Empty&);
	//Empty& operator=(const Empty&);
};

// Modern singleton
class ModernUncopyable
{
public:
	ModernUncopyable() {}

	static ModernUncopyable& getInstance()
	{
		static ModernUncopyable mu;
		return mu;
	}

public:
	// C++ 11 way of deleting the methods we don't want.
	ModernUncopyable(const ModernUncopyable&) = delete;
	void operator=(const ModernUncopyable&)   = delete;

	// Note: Scott Meyers mentions in his Effective Modern
    // C++ book, that deleted functions should generally
	// be public as it results in better error messages
	// due to the compilers behavior to check accessibility
    // before deleted status
};

int main()
{
	Empty e1;

	Empty e2(e1);
	e2 = e1;

	ModernUncopyable mu1;
	ModernUncopyable mu2;

	ModernUncopyable mu1(mu2);

	mu1 = mu2;

	std::cin.get();
}