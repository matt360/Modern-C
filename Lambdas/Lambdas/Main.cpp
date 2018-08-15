// LAMBDAS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//                                                              <return_type(parameter)>
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	std::vector<int> values = { 1, 5, 4, 2, 3 };
	// return an iterator that is the first element that matches the predicate I'm passing in
	auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3; }); // return the first instance of a value grater than 5
	std::cout << *it << std::endl;

	int a = 5;
	auto lambda = [&](int value) { std::cout << "Value: " << a << std::endl; };
	ForEach(values, lambda);

	auto lambda_mutable = [&](int value) mutable { a = 6; std::cout << "Value: " << a << std::endl; };
	ForEach(values, lambda_mutable);

	std::cin.get();
}
