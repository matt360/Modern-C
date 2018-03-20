/*
STL - Standard Template Library - A library filled with containers, container types; things that contain certain data and is called a standard 
template library because you can template it into anything. The whole library is templated meaning that the underlying data type, of the containers;
in other words, the data that the container contains, that is actually up to you to decide, the whole thing is made out of temapletes. 
You can provide the undelying data type, that this data structure actually handels. It means we don't have to write our own data structures.

std::vector - why? (It shouldn't be called vector, after: https://stackoverflow.com/questions/581426/why-is-a-c-vector-called-a-vector : It's called a vector because Alex Stepanov, the designer of the Standard Template Library, was looking for a name to distinguish it from built-in arrays. He admits now that he made a mistake, because mathematics already uses the term 'vector' for a fixed-length sequence of numbers. Now C++0X will compound this mistake by introducing a class 'array' that will behave similar to a mathematical vector.) 

To fully show what the std::vector does it could be called something like: 'array_list' or 'dynamic_array' - because that makes a lot more sense.
std::vector - is a set that doesn't enforce any kind of uniqness to its actuall elements, so in other words, it's basically an array.
But unlike the normal array types, and in C++ either just raw arrays or the standard array class, this can actually resize, which means when 
you create this vector, when you create this dyncami array, deosn't have a set size, you can give it a set size, if you want to initialize it
with a set size, you basically don't give it a size; you crate this vector/dynamic array, and then you put elemtns to it; and eveytime you put
elemnts to it, the size grows; so I can start off without actaully knowing how many elements I want in my array, and then just push 10 things into it,
and suddenly I have an array with 10 items. When you exceed that, it basically creates a new array in memory, that's bigger than the first one, 
copies everything to it, and then deletes the old one. You suddenly have basically a new array, that's somewhere elese in memory, that has a lot more
storage and you can keep adding things to it like that. In pracite, it allocates quite often.
*/

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
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
	Vertex array_vertices[5];
	Vertex* vert = new Vertex[5];
	vert[4].x;

	// it is technically more optimal, to store Vertex objects, intead of pointers, becasue of you store Vertex objects,
	// your memory is going to be inline. Dynamic arrays, are arrays in a sense that their memory is continous, which means that it's not fragmented
	// in memory. It all just in a row. And that's really optimal if you want to iterate over them, a set all of them, or read all of them.
	// They are going to be in the same cache line. 
	// The problem may arise if you want to resize the vector, because then it needs to copy all of the items in the vector. Using pointers is one way
	// of solving the problem because then, when resizing, we only copy the pointers, and not the whole objects (moving instead of copying largely
	// solves this particular issue, but there is still some sopying which is not ideal)
	// heap allocation, pointers are always your last resort, if you really need to actually do it that way.
	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 }); // using an initalizer list to initialize/specify the x, y, z
	vertices.push_back({ 4, 5, 6 });
	Function(vertices);

	for (int i = 0; i < vertices.size(); ++i)
	{
		std::cout << vertices[i] << std::endl;
	}

	for (Vertex v : vertices) // this is going to be copying each vertex into the scope of this for loop, we don't want to do that, so ->
	{
		std::cout << v << std::endl;
	}

	vertices.erase(vertices.begin() + 1); // erase takes in the iterator - object.begin() + 1 will erase the second elemnt
	for (const Vertex& v : vertices) // -> avoid copying - & makes it a reference so it's not going to copy the data
	{
		std::cout << v << std::endl;
	}

	vertices.clear(); // clear the list of vertices

	std::cin.get();
}