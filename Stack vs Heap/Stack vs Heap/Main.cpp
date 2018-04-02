// Stack vs Heap https://www.youtube.com/watch?v=wJ1L2nSIV1s&index=54&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb

// When our programme starts it gets divided into a lot more than just a stack and a heap 
// but the two we care about most is the stact and the heap
// When out application runs the operating system will load the entire programme into memory as well as allocate a whole bunch of physcial RAM
// so our application can run.
// The stack and the heap are the two areas that we have in our RAM:
// The stack is typically an area of memeory that has a pre-defined size (Usually around 2 MB)
// The heap is also an area that is (kind of) pre-defined to a default value however it can grow and change as our appication goes on.
// Stack and Heap are always physically stored in RAM, some people tend to say it's in the CPU cache (It's likely to be hot in the cache, 
// becaue we're continually accessing it, NOT ALL of it will be stored in our cache and that's not how all of it works)

// Memory in our programme is used so we can actually store data, we need a place to store data so we can actally run our programme;
// Whether it'd be our local variables or we read stuff from a file, we need to store our data; we need a place to store that.
// The stack and the heap are areas that we're allowed to store data.
// They work very differently. But fundamentally what they do is the same.
// We can ask C++ to give us some memory from either the stack or the heap and it will give us a block of memory of our requested size;
// if everything goes well. 

// The difference is how it allocates that memory.
// Let's say we want to store an ineger (on most platforms it's 4 bytes)
// How do we find a contiguous block of 4 bytes of memory (contiguous - means in a row); how do we find this block of 4 bytes of memory?
// The way the stack will give us this memory vs the way the heap will give us this memory - that's different.
// When we ask for the memory like that that's what we call the memory allocation or just an allocation for short.

// Stack allocation: the stack pointer that is on top of the stack moves: so if I want to allocate an integer (4 bytes), we move the stack pointer 4 bytes. That's it.
// If I want to allcate an array (5 integers, that's 5 * 4 bytes = 20 bytes), the stack pointer moves 20 bytes, 
// For Vector3 we have 3 floats (3 * 4 bytes = 12 bytes), we just move the stack pointer 12 bytes. That is it!
// It's visible in the memory addresses that they're pretty close (int value = 0x010FF758, array = 0x010FF73C, Vector3 = 0x010FF728; these addresses will differ)

// The memory is literally stored on top of each other like a stack.
// In most stack implementations we actually grow the stack backwards that's why you'll see the higher memory addresses at the higher value
// in this example: first you'll see the integer, then the array next to the integer, and then the Vector3 next to the array.
// The idea of a stack is: we literally stack things on top of each other, that's why the stack allocation is extremly fast.
// literaly one CPU instruction: all we do is we move the stack pointer, and then we return the address of that stack pointer.

// Integer allocation, I move the stack pointer backwards 4 bytes and I return that memory address, becasue that is the beginning of my 
// block of 4 bytes. It's extremly fast.

// Use stack allocation whenever you can. Keep heap allocation for only big chunks of data.

// Main differences between the stack and the heap is the memory allocation:
// - The Stack is just one CPU instruction
// - The Heap is a whole bunch or heavy instructions of: when you start your applicaiton you get a certain amout of RAM allocated to you,
//   the program will maintain something called a free list (which keeps track of which blocks of memory are free and where they are ect.),
//   requesting memory from the operating system - if you ask for the memory it will go through the free list and give you a block of memory that is at least as big as you've requested - 
//   which then will give you a pointer to that block of memory and it will keep track of things, such as: a size of the allocation, 
//   and the fact that it's now allocated, and you can't use that block of memory anymore. There's a bunch of book-keeping going on.
//   More on malloc: http://gee.cs.oswego.edu/dl/html/malloc.html, https://people.freebsd.org/~jasone/jemalloc/bsdcan2006/jemalloc.pdf
//   Asking for more memory is really expensive


// CODE

#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3() :
		x(10), y(11), z(12) {}
};

// To DEBUG:
// Set a breakpoint at 44 (before [int value = 5;]
// Build and Run
// Go to Debug/Windows/Memory/Memory 1
// In the Memory 1/Address: type: &value to find it's address, or array to find it's address layout
int main()
{
	{ // if scope is used the stack will get freed once it reaches the end of the scope
		// stack allocation of an integer
		int value = 5;
		// stack allocation of an array
		int array[5];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		array[4] = 5;
		// stack allocation of a struct
		Vector3 vector;
	}

	// heap allocation of an integer
	int* hvalue = new int; // use new keyword to allocate on the heap; with smart pointers make_unique, make_shared is exactly the same; it will use 'new' for you
	                       // new keyword will just call a function called 'malloc' - memory allocate, and what this funciotn will do is usally call the undelying operating system
	                       // like platform specific function; and that will allocate memory for you on the heap.
	*hvalue = 5;
	// heap allocation of an array
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	// heap allocation of a struct
	Vector3* hvector = new Vector3(); // parenthesis optional

	delete hvalue;
	delete[] harray;
	delete hvector;
	std::cin.get();
}