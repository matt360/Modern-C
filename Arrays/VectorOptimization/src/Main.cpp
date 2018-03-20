/*
One of the most important rules of optimization is basically knowing your environment; and what I mean by knowing your environment is how do things work and what do I need to do exactly, and what should happen. 
To optimise your vector usage, you really should know how vector works and how you could maybe change it to work a little bit better. 
So basically the way that the standard vector actually works, you create a vector and then you start pushing back elements,
and when you add elements into that array, to that vector, if the size of the vector, if the capacity, of the vector, is not large enough
to contain this new element that you're trying to add; the vector need to allocate new memory that is at least large enough to hold this new element,
that you're trying to add, as well as, current contents of the vector and copy eveything across from that old location in memory, into the new 
location in memory, and then delete that old location. And that is one couse of slow code; it's the fact that if we continually need to reallocate,
that's the slow opearation, we need to reallocate, and we need to copy all of our existing elements, that's something we want to avoid. 
Optimization strategy: how to avoid copying our object if we're dealing with vectors and specifically dealing with object based vectors,
so we're not stoing a vector of pointers, we're actually storing a vector of objects. 

KNOWING YOUR ENVIRONMENT IS ONE OF THE MOST IMPORTANT THINGS WITH OPTIMIZATION, right now we're trying to optimize for copying so, 
we need to know when copies actually happen and why they happen.
*/

// CODE

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	// copy constructor
	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)
{

}

int main()
{
	std::vector<Vertex> vertices;
	vertices.reserve(3); // 1. Optimization strategy - reserve space
	//vertices.push_back({ 1, 2, 3 }); // using an initalizer list to initialize/specify the x, y, z
	//vertices.push_back({ 4, 5, 6 });
	//vertices.push_back(Vertex(7, 8, 9));

	vertices.emplace_back(1, 2, 3); // using an initalizer list to initialize/specify the x, y, z
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);

	std::cout << vertices.at(1) << std::endl;

	std::cin.get();
}