#include <iostream>
#include <string>
#include <stdexcept>

// Abstract class, 
// Inheritance, 
// Virtual methods,
// Virtual constructors, 
// Call virtual method from base class

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
	Player(std::string username) : m_username(username), m_age(0) {}
	Player(std::string username, std::size_t age) : Player(username) 
	{
		this->m_age = age;
	}
	Player(std::string username, std::size_t age, std::size_t level) : Player(username, age)
	{
		this->m_level = level;
	}

	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}

private:
	std::string m_username;
	std::size_t m_age;
	std::size_t	m_level = 1;
	std::size_t	m_experiencePoints = 0;
};

// Multiple inheritance
// Interfaces

class IMoveable
{
public:
	virtual void Move() = 0;
	virtual void SpeedUp() = 0;
	virtual ~IMoveable() = default;
};

class Vehicle : public IMoveable
{
public:
	Vehicle(const std::size_t startSpeed) : speed(startSpeed) {}
	virtual void DisplayInfo() = 0;

protected:
	std::size_t speed;
};

class Car : public virtual Vehicle
{
public:
	Car(const std::size_t startSpeed) : Vehicle(startSpeed)
	{
		std::cout << "Launching car system..." << std::endl;
	}
	virtual ~Car()
	{
		std::cout << "Shutting down car system..." << std::endl;
	}
	void Move() override
	{
		std::cout << "Driving at a speed of " << this->speed << " km/h" << std::endl;
	}
	void SpeedUp() override
	{
		this->speed += 10;
		std::cout << "Speed up to " << this->speed << " km/h" << std::endl;
	}
	void DisplayInfo() override
	{
		std::cout << "Speed: " << this->speed << " km/h, FuelCapacity: 60 L, MaxRange : 800 km, HorsePower : 300 HP" << std::endl;
	}
};

class Airplan : public virtual Vehicle
{
public:
	Airplan(const std::size_t startSpeed) : Vehicle(startSpeed)
	{
		std::cout << "Launching flight system..." << std::endl;
	}
	virtual ~Airplan()
	{
		std::cout << "Shutting down flight system..." << std::endl;
	}
	void Move() override
	{
		std::cout << "Flying at a speed of " << this->speed << " km/h" << std::endl;
	}
	void SpeedUp() override
	{
		this->speed += 25;
		std::cout << "Speed up to " << this->speed << " km/h" << std::endl;
	}
	void DisplayInfo() override
	{
		std::cout << "Speed: " << this->speed << " km/h, MaxAltitude: 12, 000 m, MaxDistance : 15, 000 km, FuelCapacity : 183, 380 L" << std::endl;
	}
};

class Drone : public Car, public Airplan
{
public:
	Drone(const std::size_t startSpeed) : Vehicle(startSpeed), Car(startSpeed), Airplan(startSpeed)
	{
		std::cout << "Preparing..." << std::endl;
	}
	~Drone() override
	{
		std::cout << "Mission complete..." << std::endl;
	}
	void Move() override {
		::Airplan::Move();
	}
	void SpeedUp() override {
		this->speed += 15;
		std::cout << "Speed up to " << this->speed << " km/h" << std::endl;
	}
	void DisplayInfo() override
	{
		std::cout << "Speed: " << this->speed << " km/h" << std::endl;
	}
};

int main()
{
	try
	{
		Player player1("FatCat1408");

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


		Drone* drone1 = new Drone(5);
		drone1->Move();
		drone1->SpeedUp();
		drone1->Car::DisplayInfo();
		drone1->Airplan::DisplayInfo();
		drone1->DisplayInfo();
		std::cout << std::endl;

		delete drone1;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}