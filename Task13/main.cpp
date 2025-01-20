#include <iostream>
#include <string>
#include <stdexcept>

class Human
{
public:
	static size_t counter;

	Human()
	{
		++counter;
		this->m_id = counter;
	}
	Human(const std::string& firstName, const std::string& lastName, const std::string& gender, const std::string& documentNumber, const std::string authorityNumber, const std::string& category, const std::string& city)
		: m_firstName(firstName), m_lastName(lastName), m_gender(gender), m_drivingLicence(documentNumber, authorityNumber, category, city)
	{
		++counter;
		this->m_id = counter;
	}

	void displayInfo()
	{
		std::cout << "User #" << this->m_id << std::endl;
		std::cout << "First name: " << this->m_firstName << std::endl;
		std::cout << "Last name: " << this->m_lastName << std::endl;
		std::cout << "Gender: " << this->m_gender << std::endl;
		this->m_drivingLicence.displayInfo();
	}

private:
	class DrivingLicence
	{
	public:
		DrivingLicence() = default;
		DrivingLicence(const std::string& documentNumber, const std::string& authorityNumber, const std::string& category, const std::string& city)
			: m_documentNumber(documentNumber), m_authorityNumber(authorityNumber), m_category(category), m_city(city) {}
			
		void displayInfo()
		{
			std::cout << "Driving licence #" << this->m_documentNumber << std::endl;
			std::cout << "--> Authority number: " << this->m_authorityNumber << std::endl;
			std::cout << "--> Category: " << this->m_category << std::endl;
			std::cout << "--> City: " << this->m_city << std::endl;
		}

	private:
		std::string m_documentNumber;
		std::string	m_authorityNumber;
		std::string m_category;
		std::string m_city;
	};

	std::size_t		m_id;
	std::string		m_firstName;
	std::string		m_lastName;
	std::string		m_gender;
	DrivingLicence	m_drivingLicence;
};

std::size_t Human::counter = 0;

int main()
{
	try
	{
		Human human1 = { "John", "Doe", "Male", "29552886", "2584", "B", "Kyiv" };
		Human human2 = { "Jane", "Smith", "Female", "29552887", "2585", "A", "Lviv" };
		Human human3 = { "Alex", "Johnson", "Male", "29552888", "2586", "O", "Odessa" };
		Human human4 = { "Emily", "Davis", "Female", "29552889", "2587", "AB", "Kharkiv" };
		Human human5 = { "Michael", "Brown", "Male", "29552890", "2588", "B", "Dnipro" };

		const int LENGTH = 5;
		Human humanArr[LENGTH] = { human1, human2, human3, human4, human5 };
		
		for (size_t i = 0; i < LENGTH; ++i)
		{
			humanArr[i].displayInfo();
			std::cout << std::string(25, '-') << std::endl;
		}

		Human* humanDynamicArr = new Human[5];
		delete[] humanDynamicArr;

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}