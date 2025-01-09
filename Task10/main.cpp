#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Human
{
private:
	string name;
	int age;
	int size;
	int* countOfCrypto;

public:
	Human() : name("Noname"), age(0), countOfCrypto(nullptr), size(0) {}
	Human(string name, int age, const int& size)
	{
		this->name = name;
		this->age = age;
		this->size = size;
		this->countOfCrypto = new int[size];
		for (size_t i = 0; i < size; ++i)
		{
			this->countOfCrypto[i] = rand() % 50 + 1;
		}
	}
	Human(const Human& other)
	{
		this->name = other.name;
		this->age = other.age;
		this->size = other.size;
		this->countOfCrypto = new int[other.size];
	}
	~Human()
	{
		delete[] countOfCrypto;
	}

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}

	int getAge()
	{
		return age;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	void Print()
	{
		cout << "Name: " << name
			<< "\nAge: " << age
			<< endl;
		for (size_t i = 0; i < size; ++i)
		{
			cout << countOfCrypto[i] << " ";
		}
		cout << endl;
	}

protected:

};

int main()
{
	srand(time(NULL));
	try
	{
		Human firstHuman("Volodia", 19, 5);
		firstHuman.setName("Volodymyr");
		firstHuman.setAge(19);

		Human secondHuman("Vitya", 20, 7);
		secondHuman.setName("Viktor");
		secondHuman.setAge(20);

		Human thirdHuman;

		firstHuman.Print();

		cout << endl;

		secondHuman.Print();

		cout << endl;

		thirdHuman.Print();

		return 0;
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
		return 1;
	}
}