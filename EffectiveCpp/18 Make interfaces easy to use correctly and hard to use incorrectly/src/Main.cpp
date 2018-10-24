// Created by Mateusz Zaremba

#include <iostream>
#include <string>

struct Day
{
	explicit Day(int d) : val(d) {}

	int val;
};

struct Month
{
public:
	
private:
	explicit Month(int m) : val(m) {}

	int val;
};

struct Year
{
	explicit Year(int y) : val(y) {}

	int val;
};

class Date
{
public:
	//Date(int month, int day, int year) {}
	Date(const Month& m, const Day& d, const Year& y) {}

};

int main() 
{
	Date d(Month(30), Day(3), Year(1995));

	std::cin.get();
}