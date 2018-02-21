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
	int m_X, m_Y;
	int *m_p_X;

public:
	// const after the parameter list/method name (only works in a class), means this method is not going to modify any of the actual class
	int GetX() const  
	{
		//m_X = 2; // error - method can't modify the class
		return m_X;
	}

	// return a pointer that's can't be modified, the contents of the pointer can't be modified and the function will not modify the class
	const int* const GetPX() const 
	{
		return m_p_X;
	}
};

int main()
{
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
	const int* const e = new int;
	//*d = 2; // int* const - can change the content
	//d = (int*)&MAX_AGE; // and can't reassing the actual pointer iteself to point to something else
	std::cout << "e " << *e << std::endl;

	std::cin.get();
}