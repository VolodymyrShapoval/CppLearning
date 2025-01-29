#include <iostream>
#include <string>
#include <stdexcept>

namespace shootmode
{
	class IShootingMode
	{
	public:
		virtual void Shoot() const noexcept = 0;
	};

	class SafeShootingMode : public IShootingMode
	{
	public:
		SafeShootingMode() = default;
		void Shoot() const noexcept override
		{
			std::cout << "Weapon is in SAFE mode. Cannot shoot!" << std::endl;
		}
	};

	class SingleShootingMode : public IShootingMode
	{
	public:
		void Shoot() const noexcept override
		{
			std::cout << "Weapon is in SINGLE mode" << std::endl;
		}
	};

	class BurstShootingMode : public IShootingMode
	{
	public:
		void Shoot() const noexcept override
		{
			std::cout << "Weapon is in BURST mode" << std::endl;
		}
	};

	class FullAutoShootingMode : public IShootingMode
	{
	public:
		void Shoot() const noexcept override
		{
			std::cout << "Weapon is in FULL auto" << std::endl;
		}
	};
}

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
		Weapon(shootmode::IShootingMode* mode = new shootmode::SafeShootingMode()) : m_pShootingMode(mode)
		{
			std::cout << "Loading weapon..." << std::endl;
		}
		virtual ~Weapon()
		{
			delete m_pShootingMode;
			std::cout << "Out of ammunition!" << std::endl;
		}
		const shootmode::IShootingMode& getShootingMode() const
		{
			return *this->m_pShootingMode;
		}
		void setShootingMode(shootmode::IShootingMode* mode)
		{
			if (m_pShootingMode != nullptr) {
				delete m_pShootingMode;
			}
			this->m_pShootingMode = mode;
		}
		virtual void printInfo() = 0;
		virtual void Shoot() = 0;

	protected:
		shootmode::IShootingMode* m_pShootingMode;
	};

	class Gun : public Weapon
	{
	public:
		Gun() : Weapon() {}
		Gun(shootmode::IShootingMode* mode) : Weapon(mode) {}
		void Shoot() override
		{
			m_pShootingMode->Shoot();
		}
	};

	class SubmachineGun : public Weapon
	{
	public:
		SubmachineGun() : Weapon() {}
		SubmachineGun(shootmode::IShootingMode* mode) : Weapon(mode) {}
		void Shoot() override
		{
			m_pShootingMode->Shoot();
		}
	};

	class Fort17 : public Gun
	{
	public:
		Fort17() : Gun()
		{
			printInfo();
		}
		Fort17(shootmode::IShootingMode* mode) : Gun(mode)
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
		Kolt1911(shootmode::IShootingMode* mode) : Gun(mode)
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
		M1928(shootmode::IShootingMode* mode) : SubmachineGun(mode)
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
			vhcl::Airplan::Move();
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
		gun1->setShootingMode(new shootmode::SingleShootingMode());
		player1.Shoot(gun1);

		delete gun1;
		std::cout << std::endl;

		wpn::Kolt1911* gun2 = new wpn::Kolt1911();
		player1.Shoot(gun2);
		std::cout << std::string(20, '>') << std::endl;
		gun2->setShootingMode(new shootmode::SingleShootingMode());
		player1.Shoot(gun2);

		delete gun2;
		std::cout << std::endl;

		wpn::M1928* submachineGun1 = new wpn::M1928();
		player1.Shoot(submachineGun1);
		std::cout << std::string(20, '>') << std::endl;
		submachineGun1->setShootingMode(new shootmode::BurstShootingMode());
		player1.Shoot(submachineGun1);
		std::cout << std::string(20, '>') << std::endl;
		submachineGun1->setShootingMode(new shootmode::FullAutoShootingMode());
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