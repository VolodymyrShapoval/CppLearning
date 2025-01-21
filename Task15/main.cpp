#include <iostream>
#include <string>
#include <stdexcept>

class Weapon
{
public:
	virtual void Shoot() = 0;
};

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		std::cout << "Type: Gun" << std::endl;
	}
};

class Fort17 : public Gun
{
public:
	void Shoot() override
	{
		::Gun::Shoot();
		std::cout << "16 rounds, 40-45 rounds/min, effective range: 50 m" << std::endl;
	}
};

class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

int main()
{
	try
	{
		Fort17 gun;

		Player player1;

		player1.Shoot(&gun);
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}