// Created by Mateusz Zaremba

#include <iostream>
#include <string>



int main() 
{
	int a = 5, b = 2;
	std::cout << a+++++b;

	/*
	Some might expect the lexer to parse the series of characters a+++++b as follows:

	a++ + ++b

	but according to the maximal munch principle, the lexer will take the longest sequence of characters to produce the next token(with a few exceptions).

	[lex.pptoken]�5.4�3 in the C++ standard:
	"the next preprocessing token is the longest sequence of characters that could constitute a preprocessing token, even if that would cause further lexical analysis to fail (...)."

	So after parsing a++, it is not allowed to just parse +, it has to parse ++. The sequence is thus parsed as:

	a ++ ++ + b

	which is ill-formed since post-increment requires a modifiable lvalue but the first post-increment will produce a prvalue, as per [expr.post.incr]�8.2.6�1 in the C++ standard:
	"The value of a postfix ++ expression is the value of its operand. (...) The result is a prvalue."
	*/
	std::cin.get();
}