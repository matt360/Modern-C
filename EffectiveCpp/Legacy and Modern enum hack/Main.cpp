#include <iostream>

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


int main()
{
	char* ncp_ncd = s; // non-const pointer,
				       // non-const data
	ncp_ncd += 2;
	*ncp_ncd *= 2;

	const char* ncp_cd = s; // non-const pointer,
					        // const data
	ncp_cd += 2;
	*ncp_cd *= 2;

	char* const cp_ncd = s; // const poiter
					        // non-const data
	cp_ncd += 2;
	*cp_ncd *= 2;

	const char* const cp_cd = s; // const poitner
						     	 // const data
	cp_cd += 2;
	cp_cd *= 2;
}