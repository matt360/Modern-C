// Mutable

// CODE

#include <iostream>

class Entity
{
private:
	//mutable int m_DebugCount = 0;
	std::string m_Name;
	int m_Score;
public:
	Entity() : 
		// member initializer list must keep the same order as the member declarations, it also prevents from creating an object twice
		m_Name("Unknown"), m_Score(0) 
	{
		//m_Name = "Unknown";
	}

	Entity(const std::string& name) :
		m_Name(name)
	{
		//m_Name = name;
	}

	const std::string& GetName() const
	{
		//m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName(); // because the methods are declared as const, they can be called on a const class declaration

	float x = 8;

	// lambda - a throwaway function that can be assing to a variable
	auto f = [=]() mutable
	{
		std::cout << "Hello" << std::endl;
		x++;
		std::cout << x << std::endl;
	};

	f();

	// x is still 8
	std::cout << std::scientific << x << std::endl;

	Entity e0;
	std::cout << e0.GetName() << std::endl;

	Entity e1("Cherno");
	std::cout << e1.GetName() << std::endl;
	
	std::cin.get();
}