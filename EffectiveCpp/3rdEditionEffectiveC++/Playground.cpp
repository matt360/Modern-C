#include <iostream>
#include <string>
#include <vector>

using int32 = int32_t;

class Investment                   // root class of hierarchy of investment types
{
public:

	int32 b : 1;

	const int32 foo() const
	{
		return b;
	}

	int32 bar()
	{
		return b;
	}

	const int32 bar() const
	{
		return b;
	}
}; 

Investment* createInvestment(); // return ptr to dynamically allocated
                                   // object in the Investment hierarchy;
                                   // the caller must delete it
                                   // (parameters omitted for simplicity)


// CONSTNESS //////////////////////////////////////////////////////
// a bad version of strlen that doesn't declare its argument const
int bad_strlen(char *x)
{
        strlen(x);

		return 0;
}

template<typename T>
void remove_constness(const_cast<T*>(x), T assigne)
{
	x = assigne;
}
 
int main()
{
	// note that the extra const is actually implicit in this declaration since
	// string literals are constant
	const char *x = "abc";

	// cast away const-ness for our strlen function 
	bad_strlen(const_cast<char *>(x));

	const int a = 1;
	(*const_cast<int*>(&a)) = 2;
	
	std::cout << "a: " << a << std::endl;
// CONSTNESS //////////////////////////////////////////////////////

// ARRAY //////////////////////////////////////////////////////////
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;
	std::cout << "arr[0]" << *(&arr) << std::endl;
	//for (int i = 0; i < sizeof(arr)/sizeof(arr))
///////////////////////////////////////////////////////////////////

	const Investment i{};

	int32 f = i.foo();

	const int32 g = i.bar();

	std::cout << i.b;

	std::cin.get();
}