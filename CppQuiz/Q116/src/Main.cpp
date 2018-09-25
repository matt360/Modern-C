// Created by Mateusz Zaremba

#include <iostream>
#include <string>

int y(int &) { return 1; }
int y(int &&) { return 2; }

template <class T> int f(T&& x) { return y(x); }
template <class T> int g(T&& x) { return y(std::move(x)); }
template <class T> int h(T&& x) { return y(std::forward<T>(x)); }

int main() 
{
	int i = 10;
	std::cout << f(i) << f(20);
	std::cout << g(i) << g(20);
	std::cout << h(i) << h(20);

	// output:
	// 112212

	/*
	Since C++11, std::vector has a one parameter constructor ( + allocator). [vector.cons]§26.3.11.2¶3 in the standard):
	explicit vector(size_type n, const Allocator& = Allocator())
	which constructs a vector with n value-initialized elements. Each value-initialization calls the default Foo constructor, resulting in the output aaaaa.

	The "trick" is, that before C++11, std::vector had a 2 parameter constructor ( + allocator ), 
	which constructed the container with n copies of the second parameter, which is defaulted to T().

	So this code before C++11 would output abbbbb, because the call would be equivalent to std::vector<Foo> bar(5,T()).
	*/

	std::cin.get();
}