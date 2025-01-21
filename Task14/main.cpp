#include <iostream>
#include <string>
#include <stdexcept>

class Human
{
public: 
	Human(const std::string& name) : name(name) {}
protected:
	std::string name;
};

class Student : public Human
{
public:
	Student(const std::string& name, const std::string group) 
		: Human(name), group(group) {}

protected:
	std::string group;
};

class Lecturer : public Human
{
public:
	Lecturer(const std::string& name, const std::string department)
		: Human(name), department(department) {}

protected:
	std::string department;
};

int main()
{
	try
	{
		Student student1("John", "SE-37");
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}