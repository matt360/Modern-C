// this keyword
/*
the this keyword is only accessible thorugh a member function; member function meaning a function that belongs to a class, so a method.
And inside a method we can reference 'this', and what 'this' is, is a pointer to the current object instance that the method belongs to.
In C++ we can write a method, a non-static method, and in order to call that method we need to first instantiate an object and then call
the moethod.
So the method has to be called with a valid object, and the 'this' keyword is a pointer to that object.

Tip: CTRL + hover mouse over the variable/function name to go to its defintion.
*/

// CODE
#include <iostream>
#include <string>


void PrintEntity(Entity* e);
void PrintEntity(const Entity& e);

class Entity
{
private:
	int x, y;

public:
	Entity(int x, int y)
	{
		/*
		Entity* e = this;
		e->x = x;
		*/
		// same as above
		this->x = x; // alt: (*this).x = x;
		this->y = y;

		// dereferenceing this
		Entity& e = *this; // getting back the reference

		PrintEntity(this); // pass the current instance of the class
		PrintEntity(*this); // passing const reference

		// delete this; /* DANGER you're freeing memory from the member function and if you ever decide to access any member data after you called 'delete this' it's going to explode because the memory has been freed. */
	}

	int GetX() const
	{
		// in const functions 'this' is equal to const pointer to the instance of the class, becasue putting const in the name of the function means that we're not allowed to modify the class.
		const Entity* e = this;
		// e->x = 5; error (const Enitity* this; const class pointer)
		const Entity& e = *this; // in const function we're getting const reference back

		return x;
	}

};

void PrintEntity(Entity* e)
{
	// Print
}

void PrintEntity(const Entity& e)
{
	// Print
}

int main()
{
	
	std::cin.get();
}