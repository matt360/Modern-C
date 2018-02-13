// Classes are a way to put together data and all functinality together.
// Classes are types, so they have to have a unique name
// By default everything inde the class is private, which means only functions inside that class can actally access those variables.
// Functions inside the classes are called methods.
// Classes allow us to group variables together into a type and also add functionality to tose variables.
// Classes don't give you any new functionality that you couldn't have done otherwise. They can't do anything that you can't do without classes.

// Struct vs Classes
// The only difference is that by default classes are private, and structs by default are public. That's it.
// The only reason why structs exicts in C++ is for backwards compatibility with C.
// The usage of classes and structs in code may differ but it only depends on coding convecntions:
// structs could be used to hold data, e.g.: struct Vec2 { float x, y; }; You will never use inheritance with structs of data.
// 

// Inheritance
/*
Put all of our common functionality between classes into a parent class. And then simmply make subclasses from that base class.
We can either change the funconality in ceratian ways or introduce entirely new functionality.
Inheritance gives us a way to put all of that common code between a number of classes into a base class that we don't have to keep
repeating ourselves. Kind like a template.
Class that inherits from a parent is both types.
Polymorphism - having mulitple types for a single type.
Inheritance is a way to extend the existing class and provide new funcionality to a base class.
Remember - when you create a sub-class it will contain eveything that your super-class contains.
Virtual funcitons introduced something called dynamic dispatch which compilers typically implement via V-table.
A V-table is basically a table that contains a mapping for all of the virtual funcitons inside our base class 
so we can actually map them to the correct over-written function at runtime.
*/

// Virtual functions
/*
Virtual functions allow us to over-write methods in the sub-classes. 
class B : public A {}; // B is a sub-class of A
Virtual functions aren't free: there are two run-time costs associated with virtual functions:
- Firstly: additinal memory that is required in order for us to store that v-tables so that we can dispatch to the correct function that
inludes a member pointer in the actual base class that points to the v-table.
- Secondly: everytime we call a virtual function we have to fo through that table to determine which function to actually map to, which
is an additional performace penalty.
Because of those costs some people prefer not to use virtual functions at all. Some use it all the time without any issue.
Maybe if you're on some embeded platform which has absolutely terrible performance and every CPU cycle counts maybe then avoid virtual fucntions.
Otherwise it's such a minial impact that you probably won't notice it at all.

class Entity
{
public:
	// the word 'virtual' tells the compiler to generate a v-table for this function so
	// if it's overwritten you can point to the correct function
	virtual std::string GetName() { return "Entity"; }
};

// Player is a sub-class of Entity class
class Player : public Entity // Player is an Entity
{
private:
	std::string m_Name;	
public:
	Player(const std::string& name)
		: m_Name(name) {}
	                   // override is not neccessary but it helps us find bugs (function name spelling errors ect.) 
	std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}
int mian()
{
	Entity* e = new Entity();
	PrintName(e);
	
	Player* p = new Player("Player");
	PrintName(p);
	
	std::cin.get();
}

// Pure virtual function
A pure virtual function in C++ is essentially the same as an abstract method or an inerface in other languages such as Java or C#.
Basically a pure virtual function allows us to define a function in a base class that does not have an implementation and then
force sub-classes to actually implemnt that function.

class Entity
{
public:
	// the word 'virtual' tells the compiler to generate a v-table for this function so
	// if it's overwritten you can point to the correct function
	// non pure virtual functions doesn't have to be over-written
	// pure virtual functions force the sub-class to provide it's own definition for a certain function.
	// in OOP it's quite common to create a class that consist only of unimplemented methods and then
	// force a sub-class to actaully implement them. This is something that is also referred to as an interface. 
	// An interface being a class that only consists of unimplemented methods - acting as a template of sorts.
	// This interface class doens't actually contain method implementations. It's not actually possible for us to 
	// instantiate that class. 
	virtual std::string GetName() = 0;
};

// Player is a sub-class of Entity class
class Player : public Entity // Player is an Entity
{
private:
	std::string m_Name;	
public:
	Player(const std::string& name)
		: m_Name(name) {}
	                   // override is not neccessary but it helps us find bugs (function name spelling errors ect.) 
	std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}
int mian()
{
	Entity* e = new Entity();
	PrintName(e);
	
	Player* p = new Player("Player");
	PrintName(p);
	
	std::cin.get();
}

*/

#include <iostream>

//#define LOG(x) std::cout << x << std::endl

//struct Vec2
//{
//	float x, y;
//
//	void Add(const Vec2& other)
//	{
//		x += other.x;
//		y += other.y;
//	}
//};

class Log
{
public:
	// Because it's not an enum class this enum exists inside the Log class namespace
	enum Level
	{
		// common practice - add the name of the enum to the variables inside it to avoid naming conflicts
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	// m_* - naming convenction for private members
	// Using enum restricts it to the integers from that enum (in this case 0, 1, 2)
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::count << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::count << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::count << "[INFO]: " << message << std::endl;
	}
};

int main()
{
	//LOG(5);
	
	Log log;
	log.SetLevel(Log::LevelError);
	log.Warn("Hello");


	std::cin.get();
}
