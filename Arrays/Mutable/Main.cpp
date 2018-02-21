// Mutable

// CODE

#include <iostream>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName(); // because the methods are declared as const, they can be called on a const class declaration

	int x = 8;

	// lambda - a throwaway function that can be assing to a variable
	auto f = [=]() mutable
	{
		std::cout << "Hello" << std::endl;
		x++;
		std::cout << x << std::endl;
	};

	f();

	// x is still 8
	std::cout << x << std::endl;

	//std::scientific
	std::cin.get();
}