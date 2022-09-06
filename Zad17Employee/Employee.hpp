#pragma once
#include <string>

enum class Gender {FEMALE, MALE};

class Employee
{
private:
	std::string _firstName = {};
	std::string _lastName = {};
	std::string _email = {};
	Gender _gender;
	int _salary;
	std::string _login;
	std::string _password;

};