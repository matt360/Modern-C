/*
Static method does not have a class instance.
Every non-static method that you write inside the class always gets an instance of the current class as a parameter.
That's how classes actually work behind the scenes. There's no such thing as a class. They're just functions with a hidden parameter of sorts.
A static method does not get that hidden parameter. A static method is the same as if you wrote a method outside the class.

Static is incredibly usefull for static data, data that does not change between class instances, that we actcually want to use in our classes.

2 things to consider when making a static variable:
- LIFE TIME - how long the variable will stick around for - in other words how long it will remain in the memory before it gets deleted.
- SCOPE - where we can actually access that variable. So if we declare a variable inside a function we can't access it with another function because the variable that we declared is going to be local to the function we declared it in.

Static local variable inside a function - lasts for the entire program, but is accessible only inside that funciton (the scope could be something else that a function; could be anything:
like an IF statement ect. That's why there's not much difference between a static variable in a function scope vs a static variable in a class scope: 
anything inside a class can access a static variable inside that class and anything inside a function can access a static varaible inside that function. 
*/


// CODE

#include <iostream>

struct Entity
{
	// you can have as many constructors as you want. It equivlent to overloading functions.
	Entity()
	{
	}

	Entity(float X, float Y)
	{
		x = X;
		y = Y;
	}
	static int x, y;

	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

// static variables need to be defined
int Entity::x;
int Entity::y;

// This is how a non-static class method really looks like when it's compiled. What static essentailly does; it removes the class parameter (in this case it'd be removing 'Entity')
static void Print(Entity e)
{
	std::cout << e.x << ", " << e.y << std::endl;	
}

/*
STATIC VARIABLES INSIDE A FUNCTION
Declaring a static variable inside a function is very similar to declaring it outside the function, like this:
int i = 0; // in this sense it doesn't matter if it's static or not 
           // (Making it static it would mean that it's going to be avaiable in this entire .cpp file)
           // if you want a similar behaviour to declaring the variable outside the function but you don't want to give an access to it to everyone 
		   // you can just declare it static in a local scope
*/
void Function()
{
	static int i = 0; // the i variable isn't visible in the global scope, it's just local to this function.
	i++;
	std::cout << i << std::endl;
}

/*
Singleton class is a class that should only have one instane in existance
One way of doing this*
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }

	void Hello() {}
};

Singleton* Singleton::s_Instance = nullptr;
*/

// A great example of where static could be used. To replace the previous method:
// insted of creating a static instance of a class we can create a static instance of a class in the Get function that returns a reference to that static instance of a class.
// *other way of doing this:
class Singleton
{
	/*
	// Ways to not allow for a default constructor
private:
	Singleton();

	// or
	Singleton() = delete;
	*/
public:
	static Singleton& Get() 
	{
		// by adding static we're extending the lifetime of Singleton to be essentailly forever (or for as long as the programe is running)
		// The first time we call Get() it will construct the 'Singleton instance' and then all sub-sequent times it will just return that 
		// existing instance. 
		static Singleton instance;
		return instance; 
	}

	void Hello() { std::cout << "Singleton memory address: " << &Get() << std::endl; }
};

// Singleton is a class that should only have one instance in existance
class MySingleton
{
private:
	static MySingleton* instance;

public:
	static MySingleton& Get() { return *instance; } // get MyInstance by reference
	
	void Hello() { std::cout << "MySingleton address: " << &instance << std::endl; } // address of the pointer
};

MySingleton* MySingleton::instance = NULL;

class MySimpleSingleton
{
public:
	static MySimpleSingleton Get()
	{
		static MySimpleSingleton mySimpleSingleton;
		return mySimpleSingleton;
	}

	void Hello()
	{
		std::cout << "MySimpleSingleton address: " << &MySimpleSingleton::Get() << std::endl;
	}
};

int main()
{
	Entity::x = 5;
	Entity::y = 8;
	Entity::Print();

	Function(); // i = 1
	Function(); // i = 2
	Function(); // i = 3
	Function(); // i = 4
	Function(); // i = 5
	//Singleton s;
	Singleton::Get().Hello();
	Singleton::Get().Hello();
	Singleton::Get().Hello();

	MySingleton::Get().Hello();
	MySingleton::Get().Hello();

	MySimpleSingleton::Get().Hello();
	MySimpleSingleton::Get().Hello();

	std::cin.get();
}