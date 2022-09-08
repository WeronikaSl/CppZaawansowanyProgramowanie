#pragma once
#include "Employee.hpp"
#include "EmployeeFileReaderClass.hpp"
#include <vector>
#include <fstream>


class EmployeeManager
{
private:
	std::vector<Employee> _employees = {};

public:
	EmployeeManager();
	std::vector<Employee> getEmployees() const;
	void generateLogin();
	
};