//
//  main.cpp
//  RemoveElementFromVector
//
//  Created by Mateusz Zaremba on 07/04/2018.
//  Copyright © 2018 Mateusz Zaremba. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T, typename Container = std::vector<T> >
void RemoveElementFromVector(Container& dynamic_array, const T& value)
{
	dynamic_array.erase(std::remove(dynamic_array.begin(), dynamic_array.end(), value), dynamic_array.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& other)
{
	for (auto c : other)
		stream << c << " ";

	return stream;
}

int main(int argc, const char * argv[]) {
	std::vector<unsigned> dynamic_array{ 1, 2, 3, 3, 4, 5 };
	RemoveElementFromVector(dynamic_array, 3);

	std::cout << dynamic_array;

	std::cin.get();
}