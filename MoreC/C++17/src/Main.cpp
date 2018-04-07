// C++17
/*
- Template deduction of constructors, allowing std::pair(5.0, false) instead of std::pair<double,bool>(5.0, false)
- 
*/

#include <iostream>

int getTwoReturnValues()
{
	int a = 0, b = 0;
	return a, b;
}

int main()
{
	int a, b;
	//auto[a, b] = getTwoReturnValues();


}