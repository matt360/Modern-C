#include <iostream>

struct S
{
	S() {}
	S(int N, std::string S, float D) 
		: n(N), s(S), d(D) {}

	int n;
	std::string s;
	float d;
};

template <std::size_t I>
auto& get(S& s)
{
	if constexpr (I == 0)
		return s.n;
	else if constexpr (I == 1)
		return s.s;
	else if constexpr (I == 2)
		return s.d;
}


int main()
{
	S s(1, "Hello", 2.0);
	std::cout << get<0>(s);
	
	std::cin.get();
}