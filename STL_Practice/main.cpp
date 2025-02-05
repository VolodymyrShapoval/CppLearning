#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include "VectorDisplay.h"
#include "VectorGenerator.h"
#include "ListDisplay.h"

void menu()
{
	std::cout << "1. Vector \n"
			<< "2. List \n"
			<< "0. Exit \n";
}

void clearConsole() {
#ifdef _WIN32
	system("cls");  // Windows
#else
	system("clear");  // Linux/macOS
#endif
}

int main()
{
	try
	{
		while (true)
		{
			menu();
			std::size_t choice;
			std::cout << "Input: ";
			std::cin >> choice;

			std::cout << std::string(20, '>') << std::endl;
			clearConsole();

			switch (choice)
			{
			case 1:
			{
				std::vector<int> templateVec;
				VectorGenerator<int>::generate_vector(templateVec, 10);
				VectorDisplay<int>::vector_work(templateVec, 15);
				templateVec.resize(15);
				VectorDisplay<int>::print(templateVec);
				VectorGenerator<int>::redefine_vector(templateVec);
				VectorDisplay<int>::print(templateVec);
				break;
			}
			case 2:
			{
				std::list<int> intList = ListDisplay<int>::generate(10);
				std::list<double> doubleList = ListDisplay<double>::generate(10);
				std::cout << "List<int>: ";
				ListDisplay<int>::print(intList);
				std::cout << "List<double>: ";
				ListDisplay<double>::print(doubleList);
				break;
			}
			case 0:
				return 0;
			default:
				std::cout << "There is no such option!" << std::endl;
				break;
			}
			std::cout << std::string(20, '>') << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}