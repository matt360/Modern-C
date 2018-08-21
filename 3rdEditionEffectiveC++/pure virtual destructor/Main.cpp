#include <iostream>
#include <string>
#include <vector>

/*
Occasionally it can be convenient to give a class a pure virtual
destructor. Recall that pure virtual functions result in abstract classes
— classes that can’t be instantiated (i.e., you can’t create objects of
that type). Sometimes, however, you have a class that you’d like to be
abstract, but you don’t have any pure virtual functions. What to do?
Well, because an abstract class is intended to be used as a base class,
and because a base class should have a virtual destructor, and
because a pure virtual function yields an abstract class, the solution
is simple: declare a pure virtual destructor in the class you want to be
abstract. Here’s an example:
*/

class AWOV                  // AWOV = "Abstract w/o Virtuals"
{
public:
	virtual ~AWOV() = 0;    // declare pure virtual destructor
};

int main()
{



	std::cin.get();
}