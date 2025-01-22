#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

int main()
{
	try
	{
		const std::string PATH = "myFile.txt";
		std::ofstream fileOut;
		fileOut.open(PATH, std::ios::app);

		if (!fileOut.is_open())
		{
			throw std::ios_base::failure("Failed to open file at path " + PATH);
		}

		fileOut << "Working with \"fstream\" library." << std::endl;
		fileOut << "Continue learning C++..." << std::endl;

		fileOut.close();
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}