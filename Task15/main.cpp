#include <iostream>
#include <string>
#include <stdexcept>

namespace wpn
{
	// Abstract class, 
	// Inheritance, 
	// Virtual methods,
	// Virtual constructors, 
	// Call virtual method from base class

	class Weapon
	{
	public:
		enum WeaponShootingMode
		{
			SAFE,
			SINGLE,
			BURST,
			FULL_AUTO
		};
		Weapon(WeaponShootingMode mode = WeaponShootingMode::SAFE) : m_shootingMode(mode)
		{
			std::cout << "Loading weapon..." << std::endl;
		}
		virtual ~Weapon()
		{
			std::cout << "Out of ammunition!" << std::endl;
		}
		WeaponShootingMode getShootingMode() const
		{
			return this->m_shootingMode;
		}
		void setShootingMode(WeaponShootingMode mode)
		{
			this->m_shootingMode = mode;
		}
		virtual void printInfo() = 0;
		virtual void Shoot() = 0;

	protected:
		WeaponShootingMode m_shootingMode;
	};

	class Gun : public Weapon
	{
	public:
		Gun() : Weapon() {}
		Gun(WeaponShootingMode mode) : Weapon(mode) {}
		void Shoot() override
		{
			switch (m_shootingMode)
			{
			case SAFE:
				std::cout << "Weapon is in SAFE mode. Cannot shoot!" << std::endl;
				break;
			case SINGLE:
				std::cout << "Weapon is in SINGLE mode" << std::endl;
				break;
			}
		}
	};

	class SubmachineGun : public Weapon
	{
	public:
		SubmachineGun() : Weapon() {}
		SubmachineGun(WeaponShootingMode mode) : Weapon(mode) {}
		void Shoot() override
		{
			switch (m_shootingMode)
			{
			case SAFE:
				std::cout << "Weapon is in SAFE mode. Cannot shoot!" << std::endl;
				break;
			case BURST:
				std::cout << "Weapon is in BURST mode" << std::endl;
				break;
			case FULL_AUTO:
				std::cout << "Weapon is in FULL auto" << std::endl;
				break;
			}
		}
	};

	class Fort17 : public Gun
	{
	public:
		Fort17() : Gun()
		{
			printInfo();
		}
		Fort17(WeaponShootingMode mode) : Gun(mode)
		{
			printInfo();
		}
		void printInfo() override
		{
			std::cout << "Title: Fort17" << std::endl;
			std::cout << "16 rounds, 40-45 rounds/min, effective range: 50 m" << std::endl;
		}
	};

	class Kolt1911 : public Gun
	{
	public:
		Kolt1911() : Gun()
		{
			printInfo();
		}
		Kolt1911(WeaponShootingMode mode) : Gun(mode)
		{
			printInfo();
		}
		void printInfo() override
		{
			std::cout << "Title: Kolt1911" << std::endl;
			std::cout << "7-8 rounds, 40-50 rounds/min, effective range: 50 m" << std::endl;
		}
	};

	class M1928 : public SubmachineGun
	{
	public:
		M1928() : SubmachineGun()
		{
			printInfo();
		}
		M1928(WeaponShootingMode mode) : SubmachineGun(mode)
		{
			printInfo();
		}
		void printInfo() override
		{
			std::cout << "Title: Thompson M1928" << std::endl;
			std::cout << "20-30 rounds, 600-725 rounds/min, effective range: 150 m" << std::endl;
		}
	};
}

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

	void Shoot(wpn::Weapon* weapon)
	{
		if (weapon == nullptr)
		{
			throw std::exception("Weapon does not exist!");
		}
		weapon->Shoot();
	}

private:
	std::string m_username;
	std::size_t m_age;
	std::size_t	m_level = 1;
	std::size_t	m_experiencePoints = 0;
};

namespace vhcl
{
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
}

int main()
{
	try
	{
		Player player1("FatCat1408");

		wpn::Weapon* gun1 = new wpn::Fort17(); 
		player1.Shoot(gun1);
		std::cout << std::string(20, '>') << std::endl;
		gun1->setShootingMode(wpn::Weapon::WeaponShootingMode::SINGLE);
		player1.Shoot(gun1);

		delete gun1;
		std::cout << std::endl;

		wpn::Kolt1911* gun2 = new wpn::Kolt1911();
		player1.Shoot(gun2);
		std::cout << std::string(20, '>') << std::endl;
		gun2->setShootingMode(wpn::Weapon::WeaponShootingMode::SINGLE);
		player1.Shoot(gun2);

		delete gun2;
		std::cout << std::endl;

		wpn::M1928* submachineGun1 = new wpn::M1928();
		player1.Shoot(submachineGun1);
		std::cout << std::string(20, '>') << std::endl;
		submachineGun1->setShootingMode(wpn::Weapon::WeaponShootingMode::BURST);
		player1.Shoot(submachineGun1);
		std::cout << std::string(20, '>') << std::endl;
		submachineGun1->setShootingMode(wpn::Weapon::WeaponShootingMode::FULL_AUTO);
		player1.Shoot(submachineGun1);

		delete submachineGun1;
		std::cout << std::endl;


		vhcl::Drone* drone1 = new vhcl::Drone(5);
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