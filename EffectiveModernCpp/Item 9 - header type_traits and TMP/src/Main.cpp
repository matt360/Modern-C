// Created by Mateusz Zaremba

#include <iostream>
#include <string>
#include <type_traits>


std::remove_const<T>::type			// yields T from const T

std::remove_reference<T>::type		// yields T from T& and T&&

std::add_lvalue_reference<T>::type	// yields T& from T


std::remove_const<T>::type			// C++11: const T -> T
std::remove_const_t<T>				// C++14 equivalent

std::remove_reference<T>::type		// C++11: T&/T&& -> T
std::remove_reference_t<T>			// C++14 equivalent

std::add_lvalue_reference<T>::type	// C++11: T -> T&
std::add_lvalue_reference_t<T>		// C++14 equivalent

int main() 
{
	

	std::cin.get();
}