// Google interview question: https://www.youtube.com/watch?v=XKu_SEDAykw

#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

bool HasPairWithSum(const std::vector<int>& data, int sum)
{
	std::unordered_set<int> set;  // complements

	for (int value : data)
	{
		// check if I have seen the value
		if (set.find(value) != set.end())
		{
			return true;
		}

		set.insert(sum - value);
	}

	return false;
}

int main()
{
	std::vector<int> a{ 1, 2, 3, 9 };
	std::vector<int> b{ 1, 2, 3, 6 };

	HasPairWithSum(a, 8) ? std::cout << "true\n" : std::cout << "false\n";
	HasPairWithSum(b, 8) ? std::cout << "true\n" : std::cout << "false\n";

	std::cin.get();
}