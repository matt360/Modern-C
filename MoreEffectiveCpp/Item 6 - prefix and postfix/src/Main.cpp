// Created by Mateusz Zaremba

#include <iostream>
#include <string>

class UPInt { // "unlimited precision int"
public:
	UPInt& operator++();			// prefix ++
	const UPInt operator++(int);	// postfix ++
	UPInt& operator--();			// prefix --
	const UPInt operator--(int);	// postfix --
	UPInt& operator+=(int);			// a += operator for UPInts
									// and ints
};

UPInt& UPInt::operator++()
{
	*this += 1;
	return *this;
}

const UPInt UPInt::operator++(int)
{
	const UPInt oldValue = *this;	// fetch
	++(*this);						// increment

	return oldValue;				// return what was fetched
}

int main() 
{
	UPInt i;
	++i; // calls i.operator++();
	i++; // calls i.operator++(0);
	--i; // calls i.operator--();
	i--; // calls i.operator--(0);

	++++i;

	std::cin.get();
}


//UPInt& UPInt::operator+=(int)
//{
//	UPInt temp = *this + this;
//	return temp; 
//}

//UPInt& UPInt::operator--()
//{
//	*this -= 1;
//	return *this;
//}