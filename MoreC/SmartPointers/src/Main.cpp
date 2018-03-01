// Smart pointers
/*
std::unique_ptr - lasts only for as long as the scope, allocated on the heap 
std::shared_ptr - works via reference counting - a practice where you keep track of how many references you have to your pointer. 
And as soon as that reference count reaches zero that's when it gets deleted so as an example I create one shared pointer, I then
create another shared pointer and copy that and my ref counter is now 2, '1' for the first one and '1' for the second one (two refs),
when the first one dies my ref count is 1, when the last one dies my ref count is 0, so the memory gets freed.
std::weak_ptr -

*/


#include <iostream>
#include <string>
#include <memory> // smart pointers
class Entity
{
private:


public:
	Entity()
	{
		std::cout << "Creted Entity" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity" << std::endl;
	}
	
	/*
	// explicit - block implicit conversion of the constructor
	explicit Entity(int age) :
		m_Name("unknows"), m_Age(age) {}
	*/

	void Print() {};
};


int main()
{
	{
		// unique pointer
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // preferred way
		//std::unique_ptr<Entity> e0 = entity; error (not allowed behaviour)
		//std::unique_ptr<Entity> entity(new Entity); good
		//std::unique_ptr<Entity> entity = new Entity(); error

		// shared pointer
		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // pref way - one construction for both control block and object
		// std::shared_ptr<Entity> sE0(new Entity); // unprefway - two construcitons, one for the control block and one for the object

		entity->Print();
	}


	std::cin.get();
}