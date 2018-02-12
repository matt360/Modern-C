#include <iostream>

void Log(const char* message)
// misspelled definition (void Logr(const char* message)) will produce:
// 1>Main.obj : error LNK2019: unresolved external symbol "void __cdecl Log(char const *)" (?Log@@YAXPBD@Z) referenced in function _main
//                                                                      tells what function is not defined                         and where we are calling it
{
	std::cout << message << std::endl;
}