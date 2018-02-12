// The Cherno Project - How The C++ Compiler Works https://www.youtube.com/watch?v=3tIqpEmWMLI&index=6&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// The C++ compiler is responisble for taking a text file and converting it into an intermediate format called an object file.
// In going from the text file (our C++ code) to the .exe file there 2 major operations that need to happend:
// - Compiling*: 
// compiler needs to pre-process our code (any pre-process statement get evaluated then and there). 
// Turing text (parsing, tokeninzing) sorting "English" C++ language into a format that the complier can actually reason with. 
// This resulst in a syntax tree being created (Represenation of our code as an abstract syntax tree)
// The compiler's job is to convert our code into either: constant data or instructions.
// Once the compiler has created this abstract syntax tree it can begin actaully generating code: 
// the actual machine code that our CPU will execute.
// There's going to be various other data such as - a place to store all our constant variables.

// The compiler creates an obj. file for each of .cpp files

// *and Linking:


#include <iostream>

void Log(const char* message);

int main()
{
	Log("Hello World!");

	std::cin.get();
}