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
V-table.
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
