// C++17
/*
- Template deduction of constructors, allowing std::pair(5.0, false) instead of std::pair<double,bool>(5.0, false)
- link: https://www.bfilipek.com/2017/07/cpp17-details-simplifications.html#init-statement-for-ifswitch
*/

#include <tuple>
#include <iostream>
#include <string>

std::tuple<int, std::string, double, char, char, float, unsigned> returnMultipleValues()
{
	//return std::make_tuple(1, "Soni", 2.4, 'a'); // Always works
	return { 1, "String", 2.0, 'a', 'b', 1.0, 0 }; // C++ 17
}

std::tuple<int, bool, float> foo()
{
	return std::make_tuple(1, true, 1.0);
}

int main()
{
	// that is covering the defintion and initialization of 'i' and 's'
	auto [i1, s1, d1, c1, c2, f1, u1] = returnMultipleValues();

	std::cout << "auto [i1, s1, d1, c1, c2, f1, u1] = "
	          << i1 << " " << s1 << " " << d1 << " " << c1 << " " << c2 << " " << f1 << " " << u1 <<  std::endl;

	std::tuple<int, bool, float> result = foo();
	int value = std::get<0>(result);
	std::cout << "value: " << value << " value1: " << std::get<1>(result) << " value2: " << std::get<2>(result);

	int i;
	bool b;
	float f;
	std::tie(i, b, f) = foo();

	auto[value1, value2, value3] = foo();

	std::cin.get();
}