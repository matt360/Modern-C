/*
#define WAIT std::cin.get();

WAIT;;

* evaluets to:

std::cin.get();
;

* second semicolon evaluates to an empty statement

*/



#include <iostream>
#include <string>

#define WAIT std::cin.get();

// worse wersion
#ifdef PR_DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

// writing macro this way means we have to comment out the code
//#define PR_DEBUG

// writing macro this way means we can just change the value to 0
//#define PR_DEBUG 1

// or define it in the DEBUG/Properties... /'C/C++'/Preprocessor -> Preprocessor Definitions -> PR_DEBUG=1;    // Remember to not include spaces

// nice wersion
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl;
#elif defined(PR_RELEASE)
#define LOG(x)
#endif

int main()
{
	#if 1
	LOG("Hello")

	WAIT
	#endif
}