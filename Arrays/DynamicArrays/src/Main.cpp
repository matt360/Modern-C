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
elemnts to it, the size grow; 

*/

#include <iostream>
#include <string>
#include <vector>

int main()
{

	std::cin.get();
}