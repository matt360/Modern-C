// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct GeneralException
{
	virtual void print() { std::cout << "G"; }
};

struct SpecialException : public GeneralException
{
	void print() override { std::cout << "S"; }
};

void f() { throw SpecialException(); }

int main() 
{
	try
	{
		f();
	}
	catch(GeneralException e)
	{
		e.print();
	}

	// output:
	// G

	/*
	We throw a SpecialException. It is derived from GeneralException, but is caught by value, so e will have the dynamic type GeneralException, not SpecialException. This is known as slicing.

	Instead, we should have caught it by reference catch (GeneralException& e), then its dynamic type would be SpecialException, and the program would output S.
	*/

	std::cin.get();
}