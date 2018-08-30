#include <iostream>
#include <string>
#include <vector>
#include <atomic>

class Widget
{
public:
	Widget() {}
	Widget(int) {}
	int x{ 0 };  // fine, x's default value is 0
	int y = 0;   // also fine
	int z(0);    // error!

	// On the other hand, uncopyable objects (e.g., std::atomics — see Item 40) may be
	// initialized using braces or parentheses, but not using “ = ”:
	std::atomic<int> ai1{ 0 };   // fine
	//std::atomic<int> ai2(0);     // error!
	std::atomic<int> ai3 = 0;    // fine

	void foo(){
		double x, y, z;

		//int sum1{ x + y + z };   // error! sum of doubles may not be expressible as int
                                   // braced initialization prevents implicit narrowing conversions

		int sum2(x + y + z);     // okay (value of expression truncated to an int

		int sum3 = x + y + z;    // ditto

	}

};

int main()
{
	int x(0);              // initializer is in parentheses

	int y = 0;             // initializer follows "=" (assignment)

	int z{ 0 };            // initializer is in braces

	int z = { 0 };         // initializer uses "=" and braces. C++ usally treats it the same as the braces-only version.


	// The “confusing mess” lobby points out that the use of an equals sign for initialization
	// often misleads C++ newbies into thinking that an assignment is taking place, even
	// though it’s not.For built - in types like int, the difference is academic, but for userdefined
	// types, it’s important to distinguish initialization from assignment, because
	// different function calls are involved:

	Widget w1;          // call default constructor

	Widget w2 = w1;     // not an assignment; calls copy ctor

	w1 = w2;            // an assignment; calls copy operator=

	// Another noteworthy characteristic of braced initialization is its immunity to C++’s
	// most vexing parse.A side effect of C++’s rule that anything that can be parsed as a
	// declaration must be interpreted as one, the most vexing parse most frequently afflicts
	// developers when they want to default - construct an object, but inadvertently end up
	// declaring a function instead.The root of the problem is that if you want to call a constructor
	// with an argument, you can do it like this,
	Widget w1(10); // call Widget ctor with argument 10

	// but if you try to call a Widget constructor with zero arguments using the analogous
	// syntax, you declare a function instead of an object:
	Widget w2(); // most vexing parse! declares a function
	             // named w2 that returns a Widget!

	// Functions can’t be declared using braces for the parameter list, so defaultconstructing
	// an object using braces doesn’t have this problem:
	Widget w3{}; // // calls Widget ctor with no args

	std::vector<int> v{ 1, 3, 5 };    // v's initial content is 1, 3, 5

	std::vector<int> v1(10, 20);// use non-std::initializer_list
								// ctor: create 10-element
								// std::vector, all elements have
								// value of 20

	std::vector<int> v2{ 10, 20 };// use std::initializer_list ctor:
							      // create 2-element std::vector,
							      // element values are 10 and 20

	std::cin.get();
}