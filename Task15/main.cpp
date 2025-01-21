#include <iostream>
#include <string>
#include <stdexcept>

class Weapon
{
public:
	Weapon()
	{
		std::cout << "Loading weapon..." << std::endl;
	}
	virtual ~Weapon()
	{
		std::cout << "Shooting was stopped!" << std::endl;
	}
	virtual void Shoot() = 0;
	void Restart()
	{
		std::cout << "Restarting..." << std::endl;
	}
};

class Gun : public Weapon
{
public:
	~Gun() override
	{
		std::cout << "Out of ammunition!" << std::endl;
	}
	void Shoot() override
	{
		std::cout << "Type: Gun" << std::endl;
	}
};

class SubmachineGun : public Weapon
{
public:
	~SubmachineGun() override
	{
		std::cout << "Overheating" << std::endl;
	}
	void Shoot() override
	{
		std::cout << "Type: Submachine Gun" << std::endl;
	}
};

class Fort17 : public Gun
{
public:
	void Shoot() override
	{
		::Gun::Shoot();
		std::cout << "Title: Fort17" << std::endl;
		std::cout << "16 rounds, 40-45 rounds/min, effective range: 50 m" << std::endl;
	}
};

class Kolt1911 : public Gun
{
public:
	void Shoot() override
	{
		::Gun::Shoot();
		std::cout << "Title: Kolt1911" << std::endl;
		std::cout << "7-8 rounds, 40-50 rounds/min, effective range: 50 m" << std::endl;
	}
};

class M1928 : public SubmachineGun
{
public:
	void Shoot() override
	{
		::SubmachineGun::Shoot();
		std::cout << "Title: Thompson M1928" << std::endl;
		std::cout << "20-30 rounds, 600-725 rounds/min, effective range: 150 m" << std::endl;
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
		Player player1;

		Weapon* gun1 = new Fort17;
		player1.Shoot(gun1);
		gun1->Restart();
		delete gun1;
		std::cout << std::endl;

		Kolt1911* gun2 = new Kolt1911;
		player1.Shoot(gun2);
		gun2->Restart();
		delete gun2;
		std::cout << std::endl;

		M1928* submachineGun1 = new M1928;
		player1.Shoot(submachineGun1);
		submachineGun1->Restart();
		delete submachineGun1;
		std::cout << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}