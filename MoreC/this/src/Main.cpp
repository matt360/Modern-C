// this
/*
'this' keyword is only accesible to us through a member function (Member function - a function that belongs to a class - so a method).
And inside a method we can reference 'this' - and what 'this' is, is a pointer to a current object instance that the method belongs to.
So in C++ we can run a method, a non-static method, and in order to call that method we need to first instantiate an object and then call
the method; so the method has to be called with a valid object, and 'this', the 'this' keyword is a pointer to that object.
'this' is really important to how methods work in general. 
*/

// CODE
#include <iostream>
#include <string>

void PrintEntity(Entity* e);
void PrintEntity(const Entity& e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		Entity* e = this;

		//e->x = x;
		//(*this).x = x;
		this->x = x;
		this->y = y;

		PrintEntity(this);  // passing Entity by a pointer (Entity* e)
		PrintEntity(*this); // passing Entity by a const reference (const Entity& e)
	}


	int GetX() const
	{
		const Entity* e = this;
		const Entity& e = *this;

		return x;
	}
};

void PrintEntity(Entity* e)
{

}

void PrintEntity(const Entity& e)
{

}

int main()
{
	
	std::cin.get();
}

