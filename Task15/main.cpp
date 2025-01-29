#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

#define SHOOTING_MODE_PTR			std::unique_ptr<shootmode::IShootingMode> 
#define SAFE_SHOOTING_MODE_PTR		std::make_unique<shootmode::SafeShootingMode>()
#define SINGLE_SHOOTING_MODE_PTR	std::make_unique<shootmode::SingleShootingMode>()
#define BURST_SHOOTING_MODE_PTR		std::make_unique<shootmode::BurstShootingMode>()
#define FULL_AUTO_SHOOTING_MODE_PTR std::make_unique<shootmode::FullAutoShootingMode>()

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
	class Weapon
	{
	public:
		Weapon(SHOOTING_MODE_PTR mode = SAFE_SHOOTING_MODE_PTR) : m_pShootingMode(std::move(mode))
		{
			std::cout << "Loading weapon..." << std::endl;
		}
		virtual ~Weapon()
		{
			std::cout << "Out of ammunition!" << std::endl;
		}
		const SHOOTING_MODE_PTR& getShootingMode() const
		{
			return m_pShootingMode;
		}
		void setShootingMode(SHOOTING_MODE_PTR mode)
		{
			m_pShootingMode = std::move(mode);
		}
		virtual void printInfo() noexcept = 0;
		virtual void Shoot() const = 0;

	protected:
		SHOOTING_MODE_PTR m_pShootingMode;
	};

	class Gun : public Weapon
	{
	public:
		Gun() : Weapon() {}
		Gun(SHOOTING_MODE_PTR mode) : Weapon(std::move(mode)) {}
		void Shoot() const override
		{
			m_pShootingMode->Shoot();
		}
	};

	class SubmachineGun : public Weapon
	{
	public:
		SubmachineGun() : Weapon() {}
		SubmachineGun(SHOOTING_MODE_PTR mode) : Weapon(std::move(mode)) {}
		void Shoot() const override
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
		Fort17(SHOOTING_MODE_PTR mode) : Gun(std::move(mode))
		{
			printInfo();
		}
		void printInfo() noexcept override
		{
			std::cout << "-> Title: Fort17" << std::endl;
			std::cout << "\t16 rounds, 40-45 rounds/min, effective range: 50 m" << std::endl;
		}
	};

	class Kolt1911 : public Gun
	{
	public:
		Kolt1911() : Gun()
		{
			printInfo();
		}
		Kolt1911(SHOOTING_MODE_PTR mode) : Gun(std::move(mode))
		{
			printInfo();
		}
		void printInfo() noexcept override
		{
			std::cout << "-> Title: Kolt1911" << std::endl;
			std::cout << "\t7-8 rounds, 40-50 rounds/min, effective range: 50 m" << std::endl;
		}
	};

	class M1928 : public SubmachineGun
	{
	public:
		M1928() : SubmachineGun()
		{
			printInfo();
		}
		M1928(SHOOTING_MODE_PTR mode) : SubmachineGun(std::move(mode))
		{
			printInfo();
		}
		void printInfo() noexcept override
		{
			std::cout << "-> Title: Thompson M1928" << std::endl;
			std::cout << "\t20-30 rounds, 600-725 rounds/min, effective range: 150 m" << std::endl;
		}
	};
}

namespace player
{
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

		void Shoot(std::shared_ptr<wpn::Weapon> weapon) const
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
}

namespace vhcl
{
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

void clearConsole() {
#ifdef _WIN32
	system("cls");  // Windows
#else
	system("clear");  // Linux/macOS
#endif
}

void showMenu()
{
	std::cout << "1. Fort17\n"
		<< "2. Kolt1911\n"
		<< "3. M1928\n"
		<< "4. Drone\n"
		<< "0. Exit\n";
}

int main()
{
	try
	{
		player::Player player("FatCat1408");

		while (true)
		{
			showMenu();
			std::cout << "Choose weapon: ";
			std::size_t choice;
			std::cin >> choice;

			clearConsole();

			switch (choice)
			{
			case 1:
			{
				std::shared_ptr<wpn::Weapon> gun = std::make_shared<wpn::Fort17>();
				player.Shoot(gun);
				gun->setShootingMode(SINGLE_SHOOTING_MODE_PTR);
				player.Shoot(gun);
				break;
			}
			case 2:
			{
				std::shared_ptr<wpn::Kolt1911> gun = std::make_shared<wpn::Kolt1911>();
				player.Shoot(gun);
				gun->setShootingMode(SINGLE_SHOOTING_MODE_PTR);
				player.Shoot(gun);
				break;
			}
			case 3:
			{
				std::shared_ptr<wpn::M1928> submachineGun = std::make_shared<wpn::M1928>();
				player.Shoot(submachineGun);
				std::cout << std::string(20, '>') << std::endl;
				submachineGun->setShootingMode(BURST_SHOOTING_MODE_PTR);
				player.Shoot(submachineGun);
				std::cout << std::string(20, '>') << std::endl;
				submachineGun->setShootingMode(FULL_AUTO_SHOOTING_MODE_PTR);
				player.Shoot(submachineGun);
				break;
			}
			case 4:
			{
				std::unique_ptr<vhcl::Drone> drone = std::make_unique<vhcl::Drone>(5);
				drone->Move();
				drone->SpeedUp();
				drone->Car::DisplayInfo();
				drone->Airplan::DisplayInfo();
				drone->DisplayInfo();
				std::cout << std::endl;
				break;
			}
			case 0:
				return false;
			default:
				std::cout << "Invalid choice, try again." << std::endl;
				break;
			}
			std::cout << std::string(20, '>') << std::endl;
		}
	}
	catch (std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}