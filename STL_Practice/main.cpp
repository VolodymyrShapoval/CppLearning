#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <class T>
using vector_const_iter = typename std::vector<T>::const_iterator;

template <class T>
using vector_const_rev_iter = typename std::vector<T>::const_reverse_iterator;

template <class T>
void print(const std::vector<T>& myVec)
{
	if (myVec.empty())
	{
		std::cout << "Vector is empty" << std::endl;
		return;

	}

	std::cout << "myVec: ";
	for (vector_const_iter<T> it = myVec.cbegin(); it != myVec.cend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

template <class T>
void reverse_print(const std::vector<T>& myVec)
{
	if (myVec.empty())
	{
		std::cout << "Vector is empty" << std::endl;
		return;

	}

	std::cout << "myVec(reversed): ";
	for (vector_const_rev_iter<T> it = myVec.rbegin(); it != myVec.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

template <class T>
void vector_work(size_t countOfElements, const T& element, size_t reserveNumber)
{
	std::vector<T> myVec(countOfElements, element);
	myVec.reserve(reserveNumber);

	std::cout << "Is empty: " << std::boolalpha << myVec.empty() << std::endl;

	print<T>(myVec);
	reverse_print<T>(myVec);

	std::cout << "Capacity: " << myVec.capacity() << std::endl;
	myVec.shrink_to_fit();
	std::cout << "Capacity(after shrink): " << myVec.capacity() << std::endl;
}

template <class T>
void vector_work(const std::vector<T>& arr, size_t reserveNumber)
{
	std::vector<T> myVec(arr);
	myVec.reserve(reserveNumber);

	std::cout << "Is empty: " << std::boolalpha << myVec.empty() << std::endl;

	print<T>(myVec);
	reverse_print<T>(myVec);

	std::cout << "Capacity: " << myVec.capacity() << std::endl;
	myVec.shrink_to_fit();
	std::cout << "Capacity(after shrink): " << myVec.capacity() << std::endl;
}

int main()
{
	try
	{
		std::vector<int> templateVec = {1, 5, 2, 4, 7};
		vector_work<int>(templateVec, 15);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}