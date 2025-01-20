#include <iostream>
#include <string>
#include <stdexcept>

class Human
{
public:
	Human(const std::size_t id, const std::string& name, const std::string& gender, const std::string& firstName, const std::string& lastName, const std::string& documentNumber, const std::size_t authorityNumber, const std::string& category, const std::string& city)
		: id(id), name(name), gender(gender), drivingLicence(firstName, lastName, documentNumber, authorityNumber, category, city) {};

private:
	class DrivingLicence
	{
	public:
		DrivingLicence(const std::string& firstName, const std::string& lastName, const std::string& documentNumber, const std::size_t authorityNumber, const std::string& category, const std::string& city)
			: firstName(firstName), lastName(lastName), documentNumber(documentNumber), authorityNumber(authorityNumber), category(category), city(city) {}
			
	private:
		std::string firstName;
		std::string lastName;
		std::string documentNumber;
		std::size_t	authorityNumber;
		std::string category;
		std::string city;
	};

	std::size_t		id;
	std::string		name;
	std::string		gender;
	DrivingLicence	drivingLicence;
};

int main()
{
	try
	{

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}