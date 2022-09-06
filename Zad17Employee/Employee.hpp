#pragma once
#include <string>

class Employee
{
public:
	enum class Gender { FEMALE, MALE, UNKNOWN };
	Employee(std::string firstName, std::string lastName, std::string email, Gender gender, int salary);
private:
	std::string _firstName = {};
	std::string _lastName = {};
	std::string _email = {};
	Gender _gender;
	int _salary;
	std::string _login;
	std::string _password;

};