// rvalue and perfect forwarding https://www.justsoftwaresolutions.co.uk/cplusplus/rvalue_references_and_perfect_forwarding.html

#include <iostream>
#include <vector>

class X
{
	std::vector<double> data;

public:
	X() :
		data(100000) { std::cout << "constructed X!" << std::endl; } // lots of data

	X(X const& other) : // copy constructor
		data(other.data) { std::cout << "copy constructor called!" << std::endl; } // duplicate all that data

	X(X&& other) : // move constructor
		data(std::move(other.data)) { std::cout << "move constructor called!" << std::endl; } // move the data: no copies

	X& operator=(X const& other) // copy-assignment
	{
		std::cout << "copy-assignement called!" << std::endl;
		data = other.data; // copy all the data
		return *this;
	}

	X& operator=(X&& other) // move-assignment
	{
		std::cout << "move-assignment called!" << std::endl;
		data = std::move(other.data); // move the data: no copies
		return *this;
	}
};

// perfect forwarding 

// a function template can pass its arguments through to another function whilst retaining the lvalue/rvalue nature of the function arguments 
// by using std::forward. This is called "perfect forwarding", avoids excessive copying, and avoids the template author having to write
// multiple overloads for lvalue and rvalue references.

void g(X& t)  { std::cout << "lvalue" << std::endl;  };
void g(X&& t) { std::cout << "rvalue" << std::endl; };

template<typename T>
void f(T&& t)
{
	std::cout << "template function calling: g(t) ";
	g(t);

	std::cout << "template function calling: g(std::forward<T>(t)) ";
	g(std::forward<T>(t));
}

// overload
void h(X& t)
{
	std::cout << "overloaded function calling: g(std::forward<X>(t)) ";
	g(std::forward<X>(t));
}

void h(X&& t)
{
	std::cout << "overloaded function calling: g(std::forward<X>(t)) ";
	g(std::forward<X>(t));
}



int main()
{
	// copy constructor and move constructor
	std::cout << "X x1; ";
	X x1;
	std::cout << "X x2(x1); ";
	X x2(x1); // copy
	std::cout << "X x3(std::move(x1)); ";
	X x3(std::move(x1)); // no copy, move: x1 no longer has any data

	std::cout << "X make_x; ";
	X make_x(); // build an X with data
	std::cout << "x1 = make_x; ";
	x1 = make_x(); // return value is an rvalue, so move rather than copy

	// perfect forwarding
	X x;

	std::cout << std::endl;
	std::cout <<  "f(x) " << std::endl;
	f(x); // we pass a named x object to f, so T is deducted to be an lvalue reference: x&, when T is an lvalue reference, std::forward<T> is an no-operation: it just returns its argument. We therefore call the overload of g that takes an lvalue reference [void g(X& t)]

	std::cout << std::endl;
	std::cout << "f(X()) " << std::endl;
	f(X()); // in this case, std::forward<T>(t) is equivalent to static_cast<T&&>(t): it ensures that the argument is forwarded as an rvalue reference. This means that the overload of g that takes an rvalue refrence is selected [void g(X&& t)]

	std::cout << std::endl;
	std::cout << "h(x) " << std::endl;
	h(x);

	std::cout << std::endl;
	std::cout << "h(X()) " << std::endl;
	h(X());

	std::cin.get();
}