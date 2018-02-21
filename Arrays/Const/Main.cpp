// Const

/*
const doens't change much to the generated code.
A bit like visibility in classes.
To force certain rules on developers working with our code.
It's a promise that something is not going to change.
*/


// CODE

#include <iostream>

class Entity
{
private:
	int m_X; // m_X is a variable
	int *m_pX, m_Y; // m_pX is a pointer, m_Y is a variable
	int *m_pZ, *m_pW; // m_pZ is a pointer, m_pW is a pointer
	mutable int var;

public:
	// const after the parameter list/method name (only works in a class), means this method is not going to modify any of the actual class
	int GetX() const  // always mark the methods as const if they don't modify the class or are not supposed to modify it
	{
		//m_X = 2; // error - method can't modify the class
		var = 2; // var is mutable, mutable allows methods which are const to modify the variable
		return m_X;
	}

	// return a pointer that's can't be modified, the contents of the pointer can't be modified and the function will not modify the class
	const int* const GetPX() const 
	{
		return m_pX;
	}

	void SetX(int x)
	{
		m_X = x;
	}
};

// this function is passing by const reference so it can only cal  const methods that don't change the class
void PrintEntity(const Entity& e)
{
	std::cout << e.GetX() << std::endl;
}

int main()
{
	Entity e;

	const int MAX_AGE = 90;
	int* a = new int;
	*a = 2;
	a = (int*)&MAX_AGE; // (int*) - conversion from (const int*) to (int*)
	std::cout << "a " << *a << std::endl;

	// const int* (const before the asterisk - can't change the content of the pointer) 
	//const int MAX_AGE = 90;
	const int* b = new int;
	int const* d = new int(2);
	//*b = 2; // error - const int* - can't change the content of this pointer so the data at that memory address
	//*d = 2; // error - const int* - can't change the content of this pointer so the data at that memory address
	std::cout << "d " << *d << std::endl;
	b = (int*)&MAX_AGE; // (int*) - conversion from (const int*) to (int*)
	d = b;
	std::cout << "b " << *b << std::endl;
	std::cout << "d " << *d << std::endl;

	// int* const (const after the asterisk - can't reassing the pointer)
	//const int MAX_AGE = 90;
	int* const c = new int; // int* const - pointer* const - can't reassing the pointer (const is before the variable name)
	*c = 2; // int* const - can change the content
	//c = (int*)&MAX_AGE; // but can't reassing the actual pointer iteself to point to something else
	//c = nullptr;
	std::cout << "c " << *c << std::endl;

	// const int* const
	//const int MAX_AGE = 90;
	const int* const x = new int;
	//*d = 2; // int* const - can change the content
	//d = (int*)&MAX_AGE; // and can't reassing the actual pointer iteself to point to something else
	std::cout << "x " << *x << std::endl;

	std::cin.get();
}