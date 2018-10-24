#pragma once

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


class Rational {
public:
	Rational(int numerator = 0, // see Item 24 for why this
		int denominator = 1) :
		n(numerator), d(denominator)
	{} // ctor isn’t declared explicit

	int n, d;
	friend const Rational& operator*(const Rational& lhs, const Rational& rhs)
	{
		static Rational result;

		result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);

		return result;
	}


	friend bool operator==(const Rational& lhs, const Rational& rhs)
	{
		return (lhs.n == rhs.n && lhs.d == rhs.d);
	}

	static const int sI = 5; // you can declare and use without a definition, class-specific constans that are static and of integral type
	static const float sF;

	// "the enum hack" - outdated,
	//enum { NumTurns = 6 };
	// modern way sovling the same problem
	static constexpr uint8_t NumTurns = 6;

	int scores[NumTurns];

	char s[NumTurns] = "hello";

	char* p = s; // non-const pointer,
				 // non-const data

	const char* p = s; // non-const pointer,
					   // const data

	char* const p = s; // const poiter
					   // non-const data

	const char* const p = s; // const poitner
							 // const data
};

const float Rational::sF = 5.0f;

template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	a > b ? a : b;
}

int main()
{
	Rational a(1, 2), b(3, 4), c(5, 6), d(7, 8);

	std::cout << a.n << a.d << '\n';

	if ((a * b) == (c * d)) {
		std::cout << "a == b\n";
	}
	else {
		std::cout << "a != b\n";
	}

	Rational rat;
	rat.scores[0] = 1;
	std::cout << "scores[0] = " << rat.scores[0] << '\n';
	std::cin.get();
}
