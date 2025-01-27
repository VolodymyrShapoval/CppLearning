#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class AgeException : public std::exception
{
public:
	AgeException(const char* const text, const std::size_t value) : std::exception(text) 
	{
		this->m_value = value;
	}
	std::size_t getWrongData() const
	{
		return this->m_value;
	}

private:
	std::size_t m_value;
};

class Human
{
public:
	Human() : m_name("Noname"), m_age(0) {}
	Human(const std::string& name, const std::size_t age) : m_name(name), m_age(age)
	{
		if (age > 120)
		{
			throw AgeException("Value cannot be greater than 120!", age);
		}
	}
	Human(const Human&& other)
	{
		if (other.m_name == "" || other.m_age == 0)
		{
			throw AgeException("Value cannot be greater than 120!", other.m_age);
		}
		this->m_name = other.m_name;
		this->m_age = other.m_age;
	}

	friend std::ostream& operator <<(std::ostream& os, const Human& human);
	friend std::istream& operator >>(std::istream& is, Human& human);

private:
	std::string m_name;
	std::size_t m_age;
};

std::ostream& operator <<(std::ostream& os, const Human& human)
{
	os << human.m_name << "\t" << human.m_age;
	return os;
}
std::istream& operator >>(std::istream& is, Human& human)
{
	is >> human.m_name >> human.m_age;
	return is;
}

void write_to_file(const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::fstream fs;
	fs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	fs.open(PATH, std::ios_base::out | std::ios_base::app);

	if (!fs.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	std::cout << "Input data: ";
	std::string data;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, data);
	fs << data;

	fs.close();
}

template<class T>
void write_to_file(const T& object, const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::fstream fs;
	fs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	fs.open(PATH, std::ios_base::out);

	if (!fs.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	fs << object;

	fs.close();
}

void read_from_file(const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::ifstream fs;
	fs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fs.open(PATH, std::ios_base::in);

	if (!fs.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	std::string str;
	while (!fs.eof())
	{
		str = "";
		std::getline(fs, str);
		std::cout << str << std::endl;
	}

	fs.close();
}

template<class T>
void read_from_file(Human& object, const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::fstream fs;
	fs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fs.open(PATH, std::ios_base::in);

	if (!fs.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	while (!fs.eof())
	{
		fs >> object;
	}

	fs.close();
}

int main()
{
	while (true)
	{
		try
		{
			const std::string textPATH = "txtFile.txt";
			const std::string objectPATH = "objectFile.txt";

			std::cout << "1. Write string to file\n"
				<< "2. Write object to file\n"
				<< "3. Read string from file\n"
				<< "4. Read object from file\n"
				<< "0. Exit\n"
				<< "Choose operation: ";
			int choice;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				write_to_file(textPATH);
				break;
			}
			case 2:
			{
				std::string name;
				std::size_t age;

				std::cout << "Input name: ";
				std::cin >> name;
				std::cout << "Input age: ";
				std::cin >> age;

				Human* human = new Human(name, age);
				write_to_file(*human, objectPATH);
				delete human;
				break;
			}
			case 3:
				read_from_file(textPATH);
				break;
			case 4:
			{
				Human* object = new Human();
				read_from_file<Human>(*object, objectPATH);
				std::cout << *object << std::endl;
				delete object;
				break;
			}
			case 0:
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
		}
		catch (const std::fstream::failure& ex)
		{
			std::cout << "File exception: " << ex.what() << " - " << ex.code() << std::endl;
		}
		catch (const AgeException& ex)
		{
			std::cout << "Age exception: " << ex.what() << std::endl;
			std::cout << "Your value: " << ex.getWrongData() << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Something goes wrong!" << std::endl;
		}
		std::cout << std::string(25, '<') << std::endl;
	}
	return 0;
}