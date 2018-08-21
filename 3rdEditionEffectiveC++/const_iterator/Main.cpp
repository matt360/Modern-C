#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(10);
	vec.push_back(10);

	const std::vector<int>::iterator iter = vec.begin();
	*iter *= 10;
	++iter;

	std::vector<int>::const_iterator cIter = vec.begin();
	*cIter *= 10;
	++cIter;

	// const_pointer - const data
	std::vector<int>::const_pointer cPointer = &vec.at(2);

	cPointer += 2;
	*cPointer += 2;

	std::cin.get();
}