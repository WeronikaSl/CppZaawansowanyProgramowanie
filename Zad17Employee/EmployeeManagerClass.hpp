#pragma once
#include "Employee.hpp"
#include <vector>
#include <algorithm>


class EmployeeManager
{
private:
	std::vector<Employee> _employees = {};
	std::vector<Employee> createVecOfEmployees(std::vector<std::string> v);

public:
	EmployeeManager(std::ifstream& file);
};