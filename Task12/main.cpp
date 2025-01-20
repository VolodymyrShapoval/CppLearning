#include <iostream>
#include <string>
#include <stdexcept>

class Coin;

class User
{
public:
	static int count;

	User(std::string name)
	{
		++count;
		this->id = count;
		this->name = name;
		this->coins = 0;
	}

	int getCoins()
	{
		return this->coins;
	}

	static int getCount()
	{
		return count;
	}

	int getId()
	{
		return this->id;
	}

	void giveCoin(const Coin& coin);

	void takeCoin(const Coin& coin);

private:
	int id;
	std::string name;
	int coins;
};

int User::count = 0;


class Coin
{
	friend User;
public:
	Coin() : numberOfCoins(1) {};
	Coin(size_t value) : numberOfCoins(value) {};

	void giveCoin(const Coin& coin);
	void takeCoin(const Coin& coin);

private:
	int numberOfCoins;
};

int main()
{
	User user1("Volodia");
	Coin BTC(2);
	Coin EFR(5);

	std::cout << user1.getCoins() << std::endl;
	user1.giveCoin(BTC);
	std::cout << user1.getCoins() << std::endl;
	user1.giveCoin(EFR);
	std::cout << user1.getCoins() << std::endl;
	user1.takeCoin(BTC);
	std::cout << user1.getCoins() << std::endl;
	user1.takeCoin(EFR);
	std::cout << user1.getCoins() << std::endl;

	std::cout << "Users count: " << User::count << std::endl;
	User user2("Viktor"), user3("Vitaliy");
	std::cout << "Users count: " << User::count << std::endl;

	std::cout << "Users id: " << std::endl;
	std::cout << "User1: " << user1.getId() << std::endl;
	std::cout << "User2: " << user2.getId() << std::endl;
	std::cout << "User3: " << user3.getId() << std::endl;

	std::cout << "Number of users: " << User::getCount() << std::endl;
	return 0;
}

void User::giveCoin(const Coin& coin)
{
	this->coins += coin.numberOfCoins;
}

void User::takeCoin(const Coin& coin)
{
	if (coin.numberOfCoins < 0)
	{
		std::cout << "Choose positive number!" << std::endl;
		return;
	}
	this->coins -= coin.numberOfCoins;
}