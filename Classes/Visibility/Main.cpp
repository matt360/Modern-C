// Visibility
// Visibility is not visible to the CPU. It's only for humans to write a code that's easier to understand and maintain
// E.g.: when you mark something 'private' it means that you shouldn't access this from another class. If I've never seen the class
// before I should be able to say: "Okay, I'm only allowed to touch the public stuff".
// 
// CODE

#include <iostream>
#include <string>

/*
struct Entity
{
// default visibility is public
	int X, Y;
};
*/

/*
class Entity
{
// default visibility is private 
	int X, Y;
};
*/

// PRIVATE
/*
class Entity
{
// only* this 'Entity' class can actally access these variables, meaning it can read them and it can write them.
// *(a friend (friend class, friend function) of this, e.g. 'Entity' class can actually access private members from the classes)
//private:
	int X, Y;

	void Print() {}
public:
	Entity()
	{
		Print();
	}
};

// Player is a sub-class of Entity class
class Player : public Entity // Player is an Entity
{
public:
	Player()
	{
		// X = 0;   // error C2248
		// Print(); // error C2248
	}
};
*/

// PROTECTED
/*
class Entity
{
// protected - this class ('Entity') and all sub-classes along the hierarchy can also access these symbols 
protected:
	int X, Y;

	void Print() {}
public:
	Entity()
	{
		Print();
	}
};

// Player is a sub-class of Entity class
class Player : public Entity // Player is an Entity
{
public:
	Player()
	{
		X = 2;
		Print();
	}
};
*/

// PUBLIC

class Entity
{
// public - anyone can access it
public:
	int X, Y;

	void Print() {}
public:
	Entity()
	{
		Print();
	}
};

// Player is a sub-class of Entity class
class Player : public Entity // Player is an Entity
{
public:
	Player()
	{
		X = 2;
		Print();
	}
};

int main()
{
	Entity e;
	e.X = 2;

	std::cin.get();
}
