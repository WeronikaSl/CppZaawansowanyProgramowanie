#include "Employee.hpp"

void Employee::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void Employee::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void Employee::setEmail(std::string email)
{
	_email = email;
}

void Employee::setGender(Gender gender)
{
	_gender = gender;
}

void Employee::setSalary(double salary)
{
	_salary = salary;
}

void Employee::setLogin(std::string login)
{
	_login = login;
}

void Employee::setPassword(std::string password)
{
	_password = password;
}

std::string Employee::genderToString(Employee::Gender gender) const
{
	if (gender == Gender::FEMALE)
	{
		return "Kobieta";
	}
	else if (gender == Gender::MALE)
	{
		return "Mężczyzna";
	}
	else
	{
		return "Nieokreślona";
	}
}

std::string Employee::toString() const
{
	std::string output = {};
	output.append("Imię: ");
	output.append(_firstName);
	output.append(" Nazwisko: ");
	output.append(_lastName);
	output.append(" Email: ");
	output.append(_email);
	output.append(" Płeć: ");
	output.append(genderToString(_gender));
	output.append(" Wypłata: ");
	output.append(std::to_string(_salary));
	output.append(" Login: ");
	output.append(_login);
	output.append(" Hasło: ");
	output.append(_password);
	return output;
}

std::string Employee::getFirstName() const
{
	return _firstName;
}

std::string Employee::getLastName() const
{
	return _lastName;
}

std::string Employee::getLogin() const
{
	return _login;
}

std::ostream& operator<<(std::ostream& s, const Employee& other)
{
	s << other.toString() << std::endl;
	return s;
}
