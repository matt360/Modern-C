#include <iostream>
#include <string>
#include <vector>

// When an exception is thrown, exception - safe functions:
// ■ Leak no resources.
// ■ Don’t allow data structures to become corrupted.

class Bitmap {

};

class Widget{
	void swap(Widget& rhs) {         // exchange *this's and rhs's data;
	};

	Bitmap *pb;
};

// Here’s an implementation of operator= that looks reasonable on the
// surface but is unsafe in the presence of assignment to self. (It’s also
// not exception - safe, but we’ll deal with that in a moment.)
Widget& Widget::operator=(const Widget& rhs)
{
	delete pb;
	pb = new Bitmap(*rhs.pb);
	return *this;
	// The self - assignment problem here is that inside operator=, *this (the
	// target of the assignment) and rhs could be the same object. When they
	// are, the delete not only destroys the bitmap for the current object, it
	// destroys the bitmap for rhs, too. At the end of the function, the Widget
	// — which should not have been changed by the assignment to self —
	// finds itself holding a pointer to a deleted object! Probably -
	// C++ implementations are permitted to change the value of a deleted pointer
	// (e.g., to null or some other special bit pattern), but I am unaware of any that do.
}

// The traditional way to prevent this error is to check for assignment to
// self via an identity test at the top of operator=:
Widget& Widget::operator=(const Widget& rhs)
{
	if (this == &rhs) return *this;   // identity test: if a self-assignment, do nothing

	delete pb;
	pb = new Bitmap(*rhs.pb);
	return *this;
}

// Happily, making operator= exception - safe typically renders it selfassignment -
// safe, too. As a result, it’s increasingly common to deal
// with issues of self-assignment by ignoring them, focusing instead on
// achieving exception safety.Item 29 explores exception safety in depth,
// but in this Item, it suffices to observe that in many cases, a careful
// ordering of statements can yield exception-safe (and self-assignment safe)
// code. Here, for example, we just have to be careful not to delete
// pb until after we’ve copied what it points to :
Widget& Widget::operator=(const Widget& rhs)
{
	Bitmap *pOrig = pb;              // remember original pb
	pb = new Bitmap(*rhs.pb);        // point pb to a copy of rhs's bitmap
	delete pOrig;                    // delete the original pb
	return *this;
	// Now, if “new Bitmap” throws an exception, pb(and the Widget it’s inside
	// of) remains unchanged.Even without the identity test, this code handles
	// assignment to self, because we make a copy of the original bitmap,
	// point to the copy we made, then delete the original bitmap. It
	// may not be the most efficient way to handle self - assignment, but it
	// does work.

	// If you’re concerned about efficiency, you could put the identity test
	// back at the top of the function. Before doing that, however, ask yourself
	// how often you expect self-assignments to occur, because the test
	// isn’t free. It makes the code (both source and object) a bit bigger, and
	// it introduces a branch into the flow of control, both of which can
	// decrease runtime speed. The effectiveness of instruction prefetching,
	// caching, and pipelining can be reduced, for example.
}

// An alternative to manually ordering statements in operator= to make
// sure the implementation is both exception-safe and self-assignment
// is to use the technique known as “copy and swap.” This technique is
// closely associated with exception safety, so it’s described in Item 29.
// However, it’s a common enough way to write operator= that it’s worth
// seeing what such an implementation often looks like :
Widget& Widget::operator=(const Widget& rhs)
{
	Widget temp(rhs);            // make a copy of rhs's data
	swap(temp);                  // swap *this's data with the copy's
	return *this;
}

// A variation on this theme takes advantage of the facts that(1) a class’s
// copy assignment operator may be declared to take its argument by
// value and (2) passing something by value makes a copy of it.

// Personally, I worry that this approach sacrifices clarity at the altar of
// cleverness, but by moving the copying operation from the body of the
// function to construction of the parameter, it’s a fact that compilers
// can sometimes generate more efficient code.
Widget& Widget::operator=(Widget rhs)
{
	swap(rhs);
	return *this;
}

int main()
{
	// Things to Remember
	// ✦ Make sure operator= is well - behaved when an object is assigned to
	// itself.Techniques include comparing addresses of source and target
	// objects, careful statement ordering, and copy - and-swap.
	// ✦ Make sure that any function operating on more than one object behaves
	// correctly if two or more of the objects are the same.

	std::cin.get();
}