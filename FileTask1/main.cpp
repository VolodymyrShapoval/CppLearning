#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class Human
{
public:
	Human() = default;
	Human(const std::string& name, const std::size_t age) : m_name(name), m_age(age) {}
	void display_info()
	{
		std::cout << "Name: " << this->m_name << std::endl;
		std::cout << "Age: " << this->m_age << std::endl;
	}

private:
	std::string m_name;
	std::size_t m_age;
};

void write_to_file(const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::fstream fs;
	fs.open(PATH, std::ios_base::app);

	if (!fs.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	std::cout << "Input data: ";
	std::string data;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, data);
	fs << data << std::endl;

	fs.close();
}

template<class T>
void write_to_file(const T& object, const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::ofstream fout;
	fout.open(PATH, std::ios_base::in);

	if (!fout.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	fout.write((char*)&object, sizeof(T));

	fout.close();
}

void read_from_file(const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::ifstream fin;
	fin.open(PATH);

	if (!fin.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	std::string str;
	while (!fin.eof())
	{
		std::getline(fin, str);
		std::cout << str << std::endl;
	}

	fin.close();
}

template<class T>
void read_from_file(Human& object, const std::string& PATH)
{
	if (PATH.empty())
	{
		throw std::invalid_argument("The file path is empty!");
	}

	std::ifstream fin;
	fin.open(PATH, std::ios_base::out);

	if (!fin.is_open())
	{
		throw std::ios_base::failure("Failed to open file at path " + PATH);
	}

	while (fin.read((char*)&object, sizeof(T)))
	{
	}
	fin.close();
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

				Human human = Human(name, age);
				write_to_file(human, objectPATH);
				break;
			}
			case 3:
				read_from_file(textPATH);
				break;
			case 4:
			{
				Human* object = new Human();
				read_from_file<Human>(*object, objectPATH);
				object->display_info();
				break;
			}
			case 0:
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
		}
		catch (std::exception& ex)
		{
			std::cout << "Exception: " << ex.what() << std::endl;
		}
		std::cout << std::string(25, '<') << std::endl;
	}
	return 0;
}