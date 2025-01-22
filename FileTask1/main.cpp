#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

void write_to_file(const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::ofstream fout;
	fout.open(PATH, std::ios::app);

	if (!fout.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	std::cout << "Input data: ";
	std::string data;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, data);
	fout << data << std::endl;

	fout.close();
}

int main()
{
	try
	{
		const std::string PATH = "myFile.txt";

		std::cout << "1. Write to file\n"
				<< "2. Read from file\n"
				<< "0. Exit\n"
				<< "Choose operation: ";
		std::size_t choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			write_to_file(PATH);
			break;
		case 0:
			std::cout << "Goodbye!" << std::endl;
			break;
		default:
			break;
		}
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}