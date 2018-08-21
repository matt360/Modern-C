/*

1. Introduction notes

p. 5 - Enum hack:
		class GamePlayer {
		private:
			enum { NumTurns = 5 }; // "the enum hack" = makes NumTurns a symbolic name for 5

			int scored[NumTurns];  // fine
			...
		};

p. 6 - Pass-by-value means "call the copy constructor"

p. 18 - If the word const appears to the left of the asterisk, what's pointed to is constant;
		if the word const appears to the right of the asterisk, the pointer itself is constant;
		if const appears on both sides, both are constant.

p. 28 - For built-in types there's no guarantee it was initialized at all prior to its assignement.

p. 30 - A translation unit is the source code giving rise to a signle object file. It's basically a single source file,
		plus all of its #include files.

p. 42 - Chapter 2 - Item 7 - Virtual Table Pointer - Virtual Table - Virtual Functions - Each class with virtual functions
		has an associated virtual table. If a class contains a virtual functions it will increase in size by 50% to 100%!
		To avoid undesired size bloating declare a virtual destructor in a class only if that class contains at least
		one virtual function.


p. 89 - If you peek under the hood of a C++ compiler, you'll find that references are typically implemented as pointers,
		so passing something by reference usually means really possing a pointer.

p. 91 - Reference is just a name, a name for some existing object. Whenever you see the declaration for a reference, you should
		immediately ask yourself what it is another name for, because it must be another name for something.




















*/
