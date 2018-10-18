#include <iostream>
#include <random>

// Flyweight object are almost always immutable.

class Terrain
{
public:
	int tiles[3][2] = { {0, 1}, {2, 3}, {4, 5} };

	const int& getTile(int x, int y)
	{
		return tiles[x][y];
	};
};

int main()
{
	//random(10);
	Terrain terrain;


	std::cout << terrain.tiles[0][1];



	std::cin.get();
}
