#include <iostream>
#include <string>
#include <vector>

// Duff's device is a way of manually implementing loop unrolling by interleaving two syntactic constructs of C:
// the do-while loop and a switch statement (source: https://en.wikipedia.org/wiki/Duff%27s_device)

int main()
{
	int n = 3;
	int i = 0;

	switch (n % 2) {
		case 0:
			do {
				++i;
				case 1:
				++i;
			} while (--n > 0);
	}

	std::cout << i;

	std::cin.get();
}