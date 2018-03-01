#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;

public:
	Entity(const std::string& name) :
		m_Name(name), m_Age(-1) {}

	Entity(int age) :
		m_Name("unknows"), m_Age(age) {}
	
	/*
	// explicit - block implicit conversion of the constructor
	explicit Entity(int age) :
		m_Name("unknows"), m_Age(age) {}
	*/
	
};

void PrintEntity(const Entity& entity)
{
	// Printing
}

int main()
{
	//Entity a("Cherno"); 
	//Entity a = Entity("Cherno");
	//Entity a = "Cherno";
	//Entity b(22);       
	//Entity b = Entity(22);

	// Implicit conversion
	Entity b = 22;
	// best practice
	Entity c(22); 

	// Implicit conversion - Entity has a constructor that takes an int so it's possible to construct an object and pass it to the function
	PrintEntity(22);
	//PrintEntity("Cherno"); error
	PrintEntity(std::string("Cherno")); // implicit conversion into a string
	PrintEntity(Entity("Cherno"));      // implicit conversion into an Entity, and then into a string

	// Explicit
	Entity d(22);
	Entity e = (Entity)22;
	Entity f = Entity(22);

	// good for explicit because we're building an object
	PrintEntity(Entity("Cherno"));

	std::cin.get();
}