// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <list>

class Widget {};

// alias version
template<typename T>
using MyAllocListA = std::list<T, MyAlloc<T>>;	// MyAllocListA<T> is synonym for
												// std::list<T, MyAlloc<T>> 
MyAllocListA<Widget> lwA;						// client code

// typedef version
template<typename T>							// MyAllocListTD::type is synonym for
struct MyAllocListTD {							// std::list<T, MyAlloc<T>>
	typedef std::list<T, MyAlloc<T>> type;
};
MyAllocListTD<Widget> lwTD;						// client code

template<typename T>
class Widget {
private:
	MyAllocListA<T> list;
};



int main() 
{
	

	std::cin.get();
}