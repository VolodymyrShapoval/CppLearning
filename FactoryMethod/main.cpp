#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	try
	{

	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}