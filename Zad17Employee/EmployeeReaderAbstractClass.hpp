#pragma once
#include "Employee.hpp"
#include <vector>
#include <fstream>


class EmployeeReaderAbstract
{
public:
	virtual std::vector<Employee> getEmployees(std::ifstream& file) const = 0;
	virtual ~EmployeeReaderAbstract() = default;
};