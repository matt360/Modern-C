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
};

int main()
{
	Entity a("Cherno"); // Entity a = Entity("Cherno");
	Entity b(22);       // Entity b = Entity(22);

}