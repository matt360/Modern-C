#include <iostream>
#include <string>
#include <vector>

template<typename C, typename V>
void findAndInsert(C& container,              // in container, find
	const V& targetVal,                       // first occurence
	const V& insertVal)                       // of targetVal, then
{                                             // insert insertVal
	using std::cbegin;                        // there                           
	using std::cend;

	auto it = std::find(cbegin(container), cend(constainer), targetVal);
	container.insert(it, insertVal);
}

int main()
{
	std::vector<int> values;

	std::vector<int>::iterator it = std::find(values.begin(), values.end(), 1983);
	values.insert(it, 1998);


	// C++98
	typedef std::vector<int>::iterator IterT;               // typedefs
	typedef std::vector<int>::const_iterator ConstIterT;    // typedefs

	ConstIterT ci = std::find(static_cast<ConstIterT>(values.begin()), 
	                          static_cast<ConstIterT>(values.end()),
							  1983);

	//values.insert(static_cast<IterT>(ci), 1998);

	// template
	findAndInsert(values, 1983, 1998);

	std::cin.get();
}