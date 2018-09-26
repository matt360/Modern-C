// Created by Mateusz Zaremba

#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A() { cout << "A"; }
	A(const A &) { cout << "a"; }
};

class B : public virtual A
{
public:
	B() { cout << "B"; }
	B(const B &) { cout << "b"; }
};

class C : public virtual A
{
public:
	C() { cout << "C"; }
	C(const C &) { cout << "c"; }
};

class D :B, C
{
public:
	D() { cout << "D"; }
	D(const D &) { cout << "d"; }
};

int main()
{
	{
		D d1;
		D d2(d1);
	}

	// output:
	// ABCDABCd

	/*
	On the first line of main(), d1 is initialized, in the order A, B, C, D. That order is defined by [class.base.init]�15.6.2�13:
	"
	� First, and only for the constructor of the most derived class (�4.5), virtual base classes are initialized in the order they appear on a depth-first left-to-right traversal of the directed acyclic graph of base classes, where �left-to-right� is the order of appearance of the base classes in the derived class base-specifier-list.
	� Then, direct base classes are initialized in declaration order as they appear in the base-specifier-list
	(...)
	� Finally, the compound-statement of the constructor body is executed.
	"
	So the output is ABCD.

	On the second line, d2 is initialized. But why are the constructors (as opposed to the copy constructors) for the base classes, called? Why do we see ABCd instead of abcd?

	As it turns out, an implicitly-defined copy constructor would have called the copy constructor of its bases ([class.copy.ctor]�15.8.1�14: "The implicitly-defined copy/move constructor for a non-union class X performs a memberwise copy/move of its bases and members."). But when you provide a user-defined copy constructor, this is something you have to do explicitly.
	*/

	std::cin.get();
}