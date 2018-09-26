﻿// Created by Mateusz Zaremba

#include <iostream>
#include <string>

typedef long long ll;

void foo(unsigned ll)
{
	std::cout << "1";
}

void foo(unsigned long long)
{
	std::cout << "2";
}

int main() 
{
	auto i = 2ull;
	foo(2ull);

	// output:
	// 2

	/*
	[dcl.spec]§10.1¶3 in the C++ standard states, "If a type-name is encountered while parsing a decl-speciﬁer-seq, it is interpreted as part of the decl-speciﬁer-seq if and only if there is no previous defining-type-speciﬁer other than a cv-qualiﬁer in the decl-speciﬁer-seq."

	[dcl.spec]§10.1¶4 also has a note: "Since signed, unsigned, long, and short by default imply int, a type-name appearing after one of those speciﬁers is treated as the name being (re)declared."

	In void foo(unsigned ll), since unsigned implies int, ll is being redeclared as a parameter name.
	*/

	std::cin.get();
}