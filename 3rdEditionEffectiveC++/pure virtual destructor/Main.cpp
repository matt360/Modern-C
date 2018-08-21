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

// This class has a pure virtual function, so it’s abstract, and it has a virtual
// destructor, so you won’t have to worry about the destructor problem.
// There is one twist, however: you must provide a definition for the pure virtual destructor ->
class AWOV                  // AWOV = "Abstract w/o Virtuals"
{
public:
	virtual ~AWOV() = 0;    // declare pure virtual destructor
};

// The way destructors work is that the most derived class’s destructor
// is called first, then the destructor of each base class is called.
// Compilers will generate a call to ~AWOV from its derived classes’ destructors,
// so you have to be sure to provide a body for the function. If you don’t,
// the linker will complain.
AWOV::~AWOV() {}            // -> definition of pure virtual dtor

// The rule for giving base classes virtual destructors applies only to
// polymorphic base classes — to base classes designed to allow the
// manipulation of derived class types through base class interfaces.

// Things to Remember
// ✦ Polymorphic base classes should declare virtual destructors. If a
// class has any virtual functions, it should have a virtual destructor.
// ✦ Classes not designed to be base classes or not designed to be used
// polymorphically should not declare virtual destructors.