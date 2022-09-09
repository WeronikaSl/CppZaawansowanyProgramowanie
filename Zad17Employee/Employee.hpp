#pragma once
#include <iostream>
#include <string>


class Employee
{
public:
	enum class Gender { FEMALE, MALE, UNKNOWN };

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmail(std::string email);
	void setGender(Gender gender);
	void setSalary(double salary);
	void setLogin(std::string login);
	void setPassword(std::string password);
	std::string toString() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getLogin() const;

private:
	std::string _firstName = {};
	std::string _lastName = {};
	std::string _email = {};
	Gender _gender = Gender::UNKNOWN;
	double _salary = 0.0;
	std::string _login;
	std::string _password;

	std::string genderToString(Gender gender) const;

};

std::ostream& operator<< (std::ostream& s, const Employee& other);
