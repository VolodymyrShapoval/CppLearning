#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>


int main()
{
	try
	{
		std::vector<int> myVec1{ 53, 4, 22, 12, 61, 3, 72 };
		std::vector<int> myVec2{ 53, 4, 22, 12, 61, 3, 72 };
		bool result = std::equal(std::begin(myVec1), std::end(myVec1), std::begin(myVec2), std::end(myVec2));
		auto pairRes = std::mismatch(std::begin(myVec1), std::end(myVec1), std::begin(myVec2), std::end(myVec2));
		std::cout << std::boolalpha << "Result(equal): " << result << std::endl;
		std::cout << std::boolalpha << "Result(mismatch): " << *pairRes.first << std::endl;
		std::cout << std::boolalpha << "Result(mismatch): " << *pairRes.second << std::endl;
	}
	catch (const std::exception ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}