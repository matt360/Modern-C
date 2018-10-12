#include <iostream>
#include <algorithm>

/*
 * int increment(int x) { return (x + 1); }
 **/

 // A Functor
class increment
{
private:
	int num;
public:
	increment(int n) : num(n) {}

	// This operator overloading enables calling
	// operator function () on objects of increment
	int operator()(int arr_num) const
	{
		return num + arr_num;
	}
}; 

int main()
{
	/*
	 * int arr[] = { 1, 2, 3, 4, 5 };
	 * int n = sizeof(arr)/sizeof(arr[0]);
	 * 
	 * // Apply increment to all elements of
	 * // arr[] and store the modified elements
	 * // back in arr[]
	 * std::transform(arr, arr + n, arr, increment);
	 * 
	 * for (int i = 0; i < n; i++)
	 * {
	 * 	std::cout << arr[i] << " ";
	 * }
	 **/
	
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int to_add = 5;

	//std::transform(arr, arr + n, arr, increment(5));

	std::transform(arr, arr + n, arr, [](int x)->int { return x + 5; });

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";	
	}



	std::cin.get();
}
