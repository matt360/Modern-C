// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <memory>

class Investment                   // root class of hierarchy of investment types
{
};

Investment* createInvestment()          // return ptr to dynamically allocated
{                                       // object in the Investment hierarchy;  
	Investment* pInv = new Investment;  // the caller must delete it
	return pInv;                        // (parameters omitted for simplicity)
}
								   
void f()
{
	Investment *pInv = createInvestment();    // call factory function
	                                          // use pInv
	// relying on f always getting to its delete statement simply isn't viable
	delete pInv;                              // release object
}

void fAutomaticPointer()
{
	// std::auto_ptr - depracated in C++11
	// std::auto_ptr - removed in C++17
	std::auto_ptr<Investment> plnv(createInvestment());	// call factory function

	                                                    // use pInv as before

														// automatically
														// delete pInv via
														// auto_ptr's dtor
}

// **Resources are acquired and immediately turned over to resource-managing objects.**
// Above, the resource returned by 'createInvestment' is used to initialize
// the 'std::auto_ptr' that will manage it. 
// In fact, the idea of using objects to manage resources is often called 
// Resource Acquisition Is Initialization (RAII)
// because it's so common to acquire a resource 
// and initialize a resource-managing object in the same statement.
// Sometimes acquired resources are assigned to resource-managing objects
// instead of initializing them, but either way, every resource is immediately
// turned over to a resource-managing object at the time the resource is acquired.

// **Resource-managing objects use their destructors to ensure that resources are released.**
// Because destructors are called automatically when an object is destroyed (e.g., when
// an object goes out of scope), resources are correctly released, regardless of how
// control leaves a block. Things can get tricky when the act of releasing resources
// can lead to exceptions being thrown (Addressed in Item 8 of Effective C++ 3rd Edition).

// An alternative to 'std::auto_ptr' is a reference-counting smart pointer (RCSP)
// An RCSP is a smart pointer that keeps track of how many objects point to a particular resource
// and automatically deletes the resource when nobody is pointing to it any longer.
// As such, RCSPs offer behavior that is similar to that of garbage collection.
// Unlike garbage collection, however, RCSPs can't break cycles of reference
// (e.g., two otherwise unused objects that point to one another).
// 

void fRCSP()
{
	std::shared_ptr<Investment> pInv(createInvestment());  // call factory function
	                                                       // use pInv as before
														   // automatically delete
														   // pInv via shared_ptr's dtor
														   // 
	std::shared_ptr<Investment> pInv1(createInvestment()); // pInv1 points to the
	                                                       // object returned from
                                                           // createInvestment
														   //
	std::shared_ptr<Investment> pInv2(pInv1);              // both pInv1 and pInv2 now
	                                                       // point to the object
	pInv1 = pInv2;                                         // ditto - nothing has changed
}   // pInv1 and pInv2 are destroyed,
    // and the object they point to is
	// automatically deleted

int main() 
{
	

	std::cin.get();
}