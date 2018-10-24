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
	static Month Jan() { return Month(1); };
	static Month Feb() { return Month(2); };
	static Month Mar() { return Month(3); };
	static Month Apr() { return Month(4); };
	static Month May() { return Month(5); };
	static Month Jun() { return Month(6); };
	static Month Jul() { return Month(7); };
	static Month Aug() { return Month(8); };
	static Month Sep() { return Month(9); };
	static Month Oct() { return Month(10); };
	static Month Nov() { return Month(11); };
	static Month Dec() { return Month(12); };

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
	Date d(Month::Mar(), Day(3), Year(1995));

	std::cin.get();
}