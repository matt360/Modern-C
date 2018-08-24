#include <iostream>
#include <string>
#include <vector>

class Bitmap {

};

class Widget{
	void swap(Widget& rhs) {         // exchange *this's and rhs's data;
	};

	Bitmap *pb;
};

// The traditional way to prevent this error is to check for assignment to
// self via an identity test at the top of operator=:
Widget& Widget::operator=(const Widget& rhs)
{
	if (this == &rhs) return *this;   // identity test: if a self-assignment, do nothing
}

// Happily, making operator= exception - safe typically renders it selfassignment -
// safe, too.As a result, it’s increasingly common to deal
// with issues of self - assignment by ignoring them, focusing instead on
// achieving exception safety.Item 29 explores exception safety in depth,
// but in this Item, it suffices to observe that in many cases, a careful
// ordering of statements can yield exception - safe(and self - assignmentsafe)
// code.Here, for example, we just have to be careful not to delete
// pb until after we’ve copied what it points to :
Widget& Widget::operator=(const Widget& rhs)
{
	Bitmap *pOrig = pb;
	pb = new Bitmap(*rhs.pb);
	delete pb;
}

// An alternative to manually ordering statements in operator= to make
// sure the implementation is both exception - and self - assignment - safe
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