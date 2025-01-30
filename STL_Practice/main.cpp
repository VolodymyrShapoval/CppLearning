#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <class T>
using vector_ptr = std::unique_ptr<std::vector<T>>;

template <class T>
void print(vector_ptr<T> myVec)
{
	std::cout << "myVec: ";
	for (size_t i = 0; i < myVec->size(); ++i)
	{
		std::cout << (*myVec)[i] << " ";
	}
	std::cout << std::endl;
};

template <class T>
void vector_work(size_t countOfElements, T&& element, size_t reserveNumber)
{
	std::vector<T> myVec(countOfElements, element);
	myVec.reserve(reserveNumber);

	std::cout << "Is empty: " << std::boolalpha << myVec.empty() << std::endl;

	print<T>(std::make_unique<std::vector<T>>(myVec));

	std::cout << "Capacity: " << myVec.capacity() << std::endl;
	myVec.shrink_to_fit();
	std::cout << "Capacity(after shrink): " << myVec.capacity() << std::endl;
}

int main()
{
	try
	{
		vector_work<int>(10, 0, 15);
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}