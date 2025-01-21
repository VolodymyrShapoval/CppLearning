#include <iostream>
#include <string>
#include <stdexcept>

class Human
{
public: 
	Human(const std::string& name) : name(name) {}

	virtual void displayInfo()
	{
		std::cout << "Name: " << this->name << std::endl;
	}

protected:
	std::string name;
};

class Student : public Human
{
public:
	Student(const std::string& name, const std::string group) 
		: Human(name), group(group) {}

	void displayInfo() override
	{
		::Human::displayInfo();
		std::cout << "Group: " << this->group << std::endl;
	}

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

class KNU
{
public:
	void displayInfo(Human& human)
	{
		human.displayInfo();
	}
};

int main()
{
	try
	{
		Human human1("Kate");
		Student student1("John", "SE-37");

		KNU knu;
		knu.displayInfo(human1);
		std::cout << std::endl;
		knu.displayInfo(student1);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}