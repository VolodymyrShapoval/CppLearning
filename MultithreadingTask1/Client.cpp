#include "Client.h"

Client::Client(const std::string& firstName, const std::string& lastName) : m_firstName(firstName), m_lastName(lastName) {}
Client::Client(const std::string& firstName, const std::string& lastName, bool status) : Client::Client(firstName, lastName) 
{
	m_status = status;
}

const std::string Client::firstName() const
{
	return m_firstName;
}
const std::string Client::lastName() const
{
	return m_lastName;
}

const bool Client::status() const
{
	return m_status;
}