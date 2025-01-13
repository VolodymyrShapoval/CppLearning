#include <iostream>
#include <stdexcept>
#include <string>

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
		for (size_t i = 0; i < size; ++i)
		{
			this->countOfCrypto[i] = other.countOfCrypto[i];
		}
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

	bool areListsEqual(const Human& other)
	{
		if (this->size != other.size)
			return false;

		for (size_t i = 0; i < size; i++)
		{
			if (this->countOfCrypto[i] != other.countOfCrypto[i])
				return false;
		}
		return true;
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

	Human& operator = (const Human& other)
	{
		this->name = other.name;
		this->age = other.age;
		this->size = other.size;

		if (this->countOfCrypto != nullptr)
		{
			delete[] countOfCrypto;
		}

		this->countOfCrypto = new int[other.size];
		for (size_t i = 0; i < size; ++i)
		{
			this->countOfCrypto[i] = other.countOfCrypto[i];
		}
		return *this;
	}

	bool operator == (const Human& other)
	{
		return (this->name == other.name
			&& this->age == other.age
			&& this->areListsEqual(other));
	}

	bool operator != (const Human& other)
	{
		return !(this->name == other.name
			&& this->age == other.age
			&& this->areListsEqual(other));
	}

	// Postfix increment
	Human& operator ++()
	{
		++this->age;

		return *this;
	}

	// Prefix increment
	Human& operator ++(int value)
	{
		Human temp(*this);

		this->age++; 

		return temp;
	}

	// Postfix decrement
	Human& operator --()
	{
		--this->age;

		return *this;
	}

	// Prefix decrement
	Human& operator --(int value)
	{
		Human temp(*this);

		this->age--;

		return temp;
	}

};

class Wallet
{
public:
	int& operator [](int index)
	{
		return arr[index];
	}

private:
	int arr[5] { 53, 555, 123, 952, 71 };
};

int main()
{
	try
	{
		Human Volodia("Volodia", 19, 5);
		Human Viktor;

		Viktor = Volodia;

		Volodia.Print();
		Viktor.Print();
		bool res = Volodia == Viktor;
		cout << res << endl;

		cout << endl;

		Wallet wallet;
		cout << wallet[1] << endl;
	}
	catch(exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}