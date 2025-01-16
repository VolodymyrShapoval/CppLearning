#include <iostream>
#include <string>
#include <stdexcept>

class Coin;

class User
{
public:
	User(std::string name)
	{
		this->name = name;
		this->coins = 0;
	}

	int getCoins()
	{
		return this->coins;
	}

	void giveCoin(const Coin& coin);

	void takeCoin(const Coin& coin);

private:
	std::string name;
	int coins;
};


class Coin
{
public:
	Coin() : numberOfCoins(1) {};
	Coin(size_t value) : numberOfCoins(value) {};

	friend void User::giveCoin(const Coin& coin);
	friend void User::takeCoin(const Coin& coin);

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