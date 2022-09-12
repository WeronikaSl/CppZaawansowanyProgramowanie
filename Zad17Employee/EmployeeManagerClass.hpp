#pragma once
#include "Employee.hpp"
#include "EmployeeFileReaderClass.hpp"
#include <vector>
#include <fstream>
#include <random>
#include <sstream>
#include <regex>


class EmployeeManager
{
private:
	std::vector<Employee> _employees = {};
	bool ifLoginExists(std::string login) const;
	int draw(int a, int b) const;
	bool ifCorrectChar(char a) const;
	void regexForPassword(std::string& password) const;

public:
	EmployeeManager(std::vector<Employee> employees);
	std::vector<Employee> getEmployees() const;
	void generateLogins();
	void generatePasswords();

	
};