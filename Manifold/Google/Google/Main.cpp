// Google interview question: https://www.youtube.com/watch?v=XKu_SEDAykw

#include <iostream>
#include <vector>
#include <unordered_set>

bool HasPairWithSum(const std::vector<int>& data, int sum)
{
	std::unordered_set<int> set;  // complements

	for (int value : data)
	{
		// check if I have seen the value.
		// set.find(value) returns an iterator to the value equal to `value`.
		// If there is no such value it returns the end iterator,
		// so if (set.find(value) != set.end()) essentially means:
		// "if value has been found in set"
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