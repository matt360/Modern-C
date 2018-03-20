#include <iostream>
#include <string>

class Entity
{
public:
	int x;
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity) 
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	//Entity* GetObject() { return m_Obj; }
	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->() const
	{
		return m_Obj;
	}
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	Entity& ent = *ptr;  // dereferencing the pointer
	ent.Print();
	(*ptr).Print();
	/* *ptr.Print(); // can't write code like this because of the operator precedence - it will try to go to object.Print and dereference the result of Print */

	ptr->Print();
	ptr->x = 2;

	// Scoped Pointer (ScopedPtr)
	ScopedPtr entity = new Entity();
	entity->Print();

	const ScopedPtr const_entity = new Entity();
	const_entity->Print();

	std::cin.get();
}