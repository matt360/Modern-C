#include <iostream>
#include <string>

const std::initializer_list<std::pair<unsigned, std::string>> table {
	{ 1000000, "m"  },
	{  500000, "d"  },
	{  100000, "c"  },
	{   50000, "l"  },
	{   10000, "x"  },
	{    5000, "v"  },
	{    1000, "M"  },
	{     900, "CM" },
	{     500, "D"  },
	{     400, "CD" },
	{     100, "C"  },
	{      90, "XC" },
	{      50, "L"  },
	{      40, "XL" },
	{      10, "X"  },
	{       9, "XI" },
	{       5, "V"  },
	{       4, "IV" },
	{       1, "I"  }
};

auto toRoman(unsigned arabic)
{
	std::string roman;
	for (auto& pair : table)
	{
		while (pair.first <= arabic)
		{
			arabic -= pair.first;
			roman += pair.second;
		}
	}
	return roman;
}

int main()
{
	auto i = toRoman(5001);
	std::cout << i;

	std::cin.get();
}