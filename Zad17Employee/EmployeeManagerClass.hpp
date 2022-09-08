#pragma once
#include "Employee.hpp"
#include "EmployeeFileReaderClass.hpp"
#include <vector>
#include <fstream>


class EmployeeManager
{
private:
	std::vector<Employee> _employees = {};
	bool ifLoginExists(std::string login);

public:
	EmployeeManager();
	std::vector<Employee> getEmployees() const;
	void generateLogin();
	
};