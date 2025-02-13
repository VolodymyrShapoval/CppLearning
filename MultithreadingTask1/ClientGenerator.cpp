#include "ClientGenerator.h"

std::vector<Client> ClientGenerator::operator ()(const std::vector<std::string>& firstNames, const std::vector<std::string>& lastNames) noexcept
{
	std::vector<Client> clients;
	for (const auto& firstName : firstNames)
	{
		for (const auto& lastName : lastNames)
		{
			clients.emplace_back(firstName, lastName);
		}
	}
	return clients;
}