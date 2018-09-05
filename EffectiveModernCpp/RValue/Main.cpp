#include <iostream>
#include <string>
#include <vector>

// A useful heuristic to determine whether an expression is an lvalue is to ask if you can
// take its address.If you can, it typically is.If you can’t, it’s usually an rvalue.
// A nice feature of this heuristic is that it helps you remember that the type of an expression is
// independent of whether the expression is an lvalue or an rvalue.That is, given a type
// T, you can have lvalues of type T as well as rvalues of type T.It’s especially important
// to remember this when dealing with a parameter of rvalue reference type, because the
// parameter itself is an lvalue:

class Widget {
	public:
	Widget() {}
	Widget(Widget&& rhs) {}  // rhs is an lvalue, though it has
	                         // an rvalue reference type
};

// Here, it’d be perfectly valid to take rhs’s address inside Widget’s move constructor,
// so rhs is an lvalue, even though its type is an rvalue reference. (By similar reasoning,
// all parameters are lvalues.)

template<class T>
void processVals(const T& param)
{

};

void someFunc(Widget w) {};

int main()
{
	Widget wid;

	someFunc(wid);

	someFunc(std::move(wid));

	std::cin.get();
}