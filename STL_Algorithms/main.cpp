#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include "Person.h"

bool areAgesEqual(const Person& person1, const Person& person2)
{
	return person1.age == person2.age;
}

int main()
{
	try
	{
		std::vector<Person> myVec1
		{
			{"Alice", 25},
			{"Bob", 30},
			{"Charlie", 22},
			{"David", 35},
			{"Emma", 28}
		};
		std::vector<Person> myVec2
		{
			{"Alice", 25},
			{"Bob", 30},
			{"Charlie", 21},
			{"David", 35},
			{"Emma", 28}
		};

		bool result = std::equal(std::begin(myVec1), std::end(myVec1), std::begin(myVec2), std::end(myVec2), areAgesEqual);
		auto pairRes = std::mismatch(std::begin(myVec1), std::end(myVec1), std::begin(myVec2), std::end(myVec2), areAgesEqual);
		std::cout << std::boolalpha << "Result(equal): " << result << std::endl;
		std::cout << std::boolalpha << "Result(mismatch): " << (*pairRes.first).name << " - " << (*pairRes.first).age << std::endl;
		std::cout << std::boolalpha << "Result(mismatch): " << (*pairRes.second).name << " - " << (*pairRes.second).age << std::endl;
	}
	catch (const std::exception ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}