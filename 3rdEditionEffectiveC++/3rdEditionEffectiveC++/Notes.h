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

p. 89 - If you peek under the hood of a C++ compiler, you'll find that references are typically implemented as pointers,
		so passing something by reference usually means really possing a pointer.

p. 91 - Reference is just a name, a name for some existing object. Whenever you see the declaration for a reference, you should
		immediately ask yourself what it is another name for, because it must be another name for something.




















*/
