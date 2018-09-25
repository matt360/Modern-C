// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct X
{
	X() { std::cout << "1"; }

	X(X&) { std::cout << "2"; }

	X(const X&) { std::cout << "3"; }

	X(X&&) { std::cout << "4"; }

	~X() { std::cout << "5"; }
};

struct Y
{
	mutable X x;

	Y() = default;

	Y(const Y&) = default;
};

int main() 
{
	{
		Y y1;
		Y y2 = std::move(y1);
	}

	// output:
	// 1255

	/*
	First, the line

	Y y1;

	creates an instance of Y. Y has an X data member, which is default constructed, printing 1.

	Then,

	Y y2 = std::move(y1);

	copy-initializes another Y. The std::move turns y1 into an rvalue, but since Y has no move constructor, its copy constructor is called. The implicitly-defined copy-constructor performs a copy of x, as specified in [class.copy.ctor]�15.8.1�14:

    The implicitly-defined copy/move constructor for a non-union class X performs a memberwise copy/move of its bases and members.

	Now the question is which copy constructor is used to initialize the copy of x. Will it pick X(X &) or X(const X &)? The Y inside the Y(const Y &) copy constructor is const, but x is marked mutable, and [dcl.stc]�10.1.1�9 says:

    The mutable specifier on a class data member nullifies a const specifier applied to the containing class object and permits modification of the mutable class member even though the rest of the object is const

	So x is considered non-const, and X(X &) is a better match to overload resolution than X(const X &), because in the latter case, a const conversion has to happen. So X(X &) is called, printing 2.

	Finally, both y1 and y2 are destroyed at the end of main, printing 55.
	*/

	std::cin.get();
}