#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "VectorTraining.h"
#include "IntVectorTraining.h"

void menu()
{
	std::cout << "1. Vector \n"
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
				IntVectorTraining::generate_vector(templateVec, 10);
				VectorTraining<int>::vector_work(templateVec, 15);
				templateVec.resize(15);
				VectorTraining<int>::print(templateVec);
				IntVectorTraining::redefine_vector(templateVec);
				VectorTraining<int>::print(templateVec);
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