#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <stdexcept>
#include "VectorDisplay.h"
#include "ListDisplay.h"
#include "ForwardListDisplay.h"
#include "ArrayDisplay.h"
#include "VectorGenerator.h"
#include "ListGenerator.h"
#include "ForwardListGenerator.h"

void menu()
{
	std::cout << "1. Vector \n"
			<< "2. List \n"
			<< "3. Forward list \n"
			<< "4. Array \n"
			<< "5. Deque \n"
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
				std::list<int> intList = IntListGenerator().generate(10);
				std::list<double> doubleList = DoubleListGenerator().generate(10);
				std::cout << "List<int>: ";
				ListDisplay<int>::print(intList);
				std::cout << "List<double>: ";
				ListDisplay<double>::print(doubleList);
				break;
			}
			case 3:
			{
				std::forward_list<int> int_flist = IntForwardListGenerator().generate(10);
				std::cout << "Forward list: ";
				ForwardListDisplay<int>::print(int_flist);
				break;
			}
			case 4:
			{
				srand(time(NULL));
				std::array<int, 10> arr;
				for (auto& elem : arr)
				{
					elem = rand() % 100;
				}
				ArrayDisplay::print(arr);
				break;
			}
			case 5:
			{
				srand(time(NULL));
				std::deque<int> dq(10);

				for (auto& elem : dq)
				{
					elem = rand() % 100;
				}

				for (const auto& elem : dq)
				{
					std::cout << elem << " ";
				}
				std::cout << std::endl;
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