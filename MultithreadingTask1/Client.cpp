#include "Client.h"

Client::Client(const std::string& firstName, const std::string& lastName) : m_firstName(firstName), m_lastName(lastName) {};

const std::string Client::firstName() const
{
	return m_firstName;
}
const std::string Client::lastName() const
{
	return m_lastName;
}
