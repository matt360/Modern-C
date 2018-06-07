// rvalue

#include <iostream>
#include <vector>

class X
{
	std::vector<double> data;

public:
	X() : 
		data(100000) {} // lots of data

	X(X const& other) : // copy constructor
		data(other.data) {} // duplicate all that data

	X(X&& other) : // move constructor
		data(std::move(other.data)) {} // move the data: no copies

	X& operator=(X const& other) // copy-assignment
	{
		data = other.data; // copy all the data
		return *this;
	}

	X& operator=(X&& other) // move-assignment
	{
		data = std::move(other.data); // move the data: no copies
		return *this;
	}
};

X make_x; // build an X with data

int main()
{
	X x1;
	X x2(x1); // copy
	X x3(std::move(x1)); // no copy, move: x1 no longer has any data

	x1 = make_x; // return value is an rvalue, so move rather than copy

	std::cin.get();
}