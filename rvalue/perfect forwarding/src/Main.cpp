// rvalue and perfect forwarding

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

template<typename T>
void foo(T&& t) {};

// a function template can pass its arguments through to another function whilst retaining the lvalue/rvalue nature of the function arguments 
// by using std::forward. This is called "perfect forwarding", avoids excessive copying, and avoids the template author having to write
// multiple overloads for lvalue and rvalue references.

void g(X&& t) {};
void g(X& t) {};

template<typename T>
void f(T&& t)
{
	g(std::forward<T>(t));
}

void h(X&& t)
{
	g(t);
}

int main()
{
	// rvalue
	X x1;
	X x2(x1); // copy
	X x3(std::move(x1)); // no copy, move: x1 no longer has any data

	x1 = make_x; // return value is an rvalue, so move rather than copy

	// perfect forwarding
	X x;
	foo(x);
	foo(X());
	
	f(x);
	f(X());
	h(x);
	h(X());

	std::cin.get();
}