//  Created by Mateusz Zaremba on 07/04/2018.
//  Copyright © 2018 Mateusz Zaremba. All rights reserved.
//

#include <iostream>
#include <string>

class TextBlock
{
public:
	TextBlock() {}
	TextBlock(const std::string& s)
		:text(s)
	{}

public:
	/*const char& operator[](std::size_t position)
	{
		return text[position];
	}*/

	// when const and non-const member functions have essentially identical implementations,
	// code duplication can be avoided by having the non-const version call the const version
	char& operator[](std::size_t position);

private:
	std::string text;

};

char& TextBlock::operator[](std::size_t position)
{
	return
		const_cast<char&>(
			static_cast<const TextBlock&>(*this)[position]);
}


int main()
{
	TextBlock("Hello");



	std::cin.get();
}