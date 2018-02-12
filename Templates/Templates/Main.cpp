// Templates - https://www.youtube.com/watch?v=I-hZkUa9mIs&index=53&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// Templates are a bit like a MACRO - they let you do pretty much anything
// Template allows you to define a template that will be compiled by your usage
// You can get the compiler to write code for you based on a set of rules

// A blueprint with parametrs that get specified when the function gets called and the parametrs determine what code gets put into the template

// A bluerpint that when I decide to call that function I can speficy certain parametrs	which determine what code get actually put into the template

// Best usage example, want to create a function that is largely the same but may take in different types

#include <iostream>
#include <string>

// Instead of overloading functions we can convert it into a template

// template parametre(typename, class - both work fine) name(T)
template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}

// Call Print with an integer, Print(5)
// The template will get copied and pasted with an appropriate value
//void Print(int value)
//{
//	std::cout << value << std::endl;
//}
//
// Call Print with a string, Print("Hello")
// The template will get copied and pasted with an appropriate value
//void Print(std::string value)
//{
//	std::cout << value << std::endl;
//}
//
// Call Print with a float, Print(5.5f)
// The template will get copied and pasted with an appropriate value
//void Print(float value)
//{
//	std::cout << value << std::endl;
//}

// CLASS TEMPLATE
// Create an array class located on the stack
// Specify the size of an intiger Array during the compilation
//template<int N>
//class Array
//{
//private:
//	int m_Array[N];
//public:
//	int GetSize() { return N; }
//};

// Specify the size and type of the Array during the compilation
template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	T GetSize() { return N; }
};

// When calling Array<5> array; that's what get's created:
//class Array
//{
//private:
//	int m_Array[5];
//public:
//	int GetSize() { return 5; }
//};

int main()
{
	// in this case, T gets replaced by whatever is in the angular brackets <> 
	// 
	Print(5);
	
	// Without calling the function the Print function does not really exist
	// The Print function is just a template that gets created when we call the Print function with a given template argument
	// Print(5)

	// CLASS TEMPLATE
	// The class code gets compiled based on its usage
	Array<int, 5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}