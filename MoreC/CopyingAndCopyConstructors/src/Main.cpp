/*
COPYING AND COPY CONSTRUCTORS
Copying refers to copying data, copying memory, when we literaly want to copy one object, or primitive, or a piece of data, 
from one place to another, that we literally have to copied of it. A lot of the time we want to copy objects so we can modify them 
in certain ways, if we can avoid unnecessary copying, because we just want to read the value, we want to actually modify existing object,
we want to do it, because copying takes time.
Copying can be both a really use thing we actally need to make our programme work in a way we want it to, but on the flip side,
unnecessary copying is bad, and we want to avoid that, as much as possible, because it wastes performance.
So understanding how copying actually works in C++ and how to get it to work and also how to avoid 'getting it to work', and to avoid copying
when you don't want a copy is very important to understanding the language and being able to write C++ code efficiently and correctly.

IMPORTANT:
whenever you write code when one variable is assigned another variable you are always copying it, it's just that in the case of pointers you are
copying the pointer, that memory address, the numeric memory address, the number, [rather that the actual memory at the pointer].
when you're using '=' it's always copying (with an exception of references. With references you're only changing the underlying thing that 
it's pointing to because references are just aliases.
*/

// CODE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

struct Vector2
{
	float x, y;
};

class String // the string is made out of the array of characters
{
private:
	char* m_Buffer;       // array of characters, and this is going to point to my buffer of chars
	unsigned int m_Size;  // keep track of how big the string is
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		/*m_Buffer = new char[m_Size];
		strcpy(m_Buffer, string);*/
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0; // adding null termination character
	}

	// 1. default C++ copy constructor 
	/*String(const String& other)
		: m_Buffer(other.m_Buffer), m_Size(other.m_Size)
	{

	}*/
	// 2. default C++ copy constructor 
	/*String(const String& other)
	{
		memcpy(this, &other, sizeof(String));
	}*/

	// not allowing copying
	/*String(const String& other) = delete;*/

	// deep copying constructor
	String(const String& other)
		: m_Size(other.m_Size) // shallow copy the size
	{
		std::cout << "Copied string!" << std::endl;
		/*m_Buffer = new char[m_Size];
		strcpy(m_Buffer, other.m_Buffer);*/
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}
	
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	// friend - function is a friend of this class - means it can access its private members
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

//void PrintString(String string)
//{
//	std::cout << string << std::endl;
//}

void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{
	int a = 2;

	int b = a; // creating a copy

	b = 3; // two different variables in the memory

	Vector2 c = { 2, 3 };
	Vector2 d = c; // copying the value - there's going to be 2 different variables that occupy two different memory addresses
	d.x = 5; // c.x still remains at 2

	Vector2* e = new Vector2();
	Vector2* f = e; // copying the pointer, memory address = two pointers that have the same value; not copying the actual value
	f->x = 5; // e->x and f->x will be both changed to 5

	String string = "Mateusz";
	String second = string; // shallow copy - the content is not being copied - 'second' is just a pointer to 'string'
	/* deep copy - when you create a new variable and you assign it with another variable which has the same type, as the variable that you're actaully creating you're copying that variable, and thus you're calling the copy constructor. */

	second[2] = 'a';

	PrintString(string);
	PrintString(second);

	std::cin.get();
}