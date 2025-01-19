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
		this->name = name;
		this->coins = 0;
		this->count += 1;
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