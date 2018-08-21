//
//  main.cpp
//  RemoveElementFromVector
//
//  Created by Mateusz Zaremba on 07/04/2018.
//  Copyright © 2018 Mateusz Zaremba. All rights reserved.
//

/*
______        _       ______       ______    ___   ______   ________
|_   _ \      / \     |_   _ `.   .' ___  | .'   `.|_   _ `.|_   __  |
  | |_) |    / _ \      | | `. \ / .'   \_|/  .-.  \ | | `. \ | |_ \_|
  |  __'.   / ___ \     | |  | | | |       | |   | | | |  | | |  _| _
 _| |__) |_/ /   \ \_  _| |_.' / \ `.___.'\\  `-'  /_| |_.' /_| |__/ |
|_______/|____| |____||______.'   `.____ .' `.___.'|______.'|________|

#include <iostream>
#include <algorithm>
#include <vector>

class Rational {
public:
	Rational(int numerator = 0, // see Item 24 for why this
		int denominator = 1) {} // ctor isn’t declared explicit

	int n, d;
	friend const Rational operator*(const Rational& lhs, const Rational& rhs)
	{
		static Rational result;

		result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);

		return result;
	}


	friend bool operator==(const Rational& lhs, const Rational& rhs)
	{
		return (lhs.n == rhs.n && lhs.d == rhs.d);
	}

};

int main()
{
	Rational a, b, c, d;

	if ((a * b) == (c * d)) {
		std::cout << "a == b";
	}
	else {
		std::cout << "a != b";
	}

	std::cin.get();
}
*/