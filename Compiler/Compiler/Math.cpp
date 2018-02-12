// For this example go to: Debug/Properties/...C++/Preprocessor/Process to a File (Yes); this option suppresses compilation, thus it does not produce an .obj file
//#define INTEGER int
//#include <iostream>
//
//#if 1
//INTEGER Mulitply(int a, int b)
//{
//	INTEGER result = a * b;
//	return result;
//#include "EndBrace.h"
//#endif 

// To read an .obj file:
// Debug/Properties/...C++/Output Files/Assembler Output/Assembly-Obly Listing (/FA)

// For optimization:
// Debug/Properties/...C++/Optimization/Optimization/Maximize Speed (/O2)
// And:
// Debug/Properties/...C++/Code Generation/Basic Runtime Checks/Default - the code that compiler will insert to help us with debugging
int Mulitply(int a, int b)
{
	int result = a * b;
	return result;
}

// this will result in constant folding (5 * 2 will be replaced by 10) anything taht is constant and can be worked out during the compile time - is;
int Multiply()
{
	return 5 * 2;
}
