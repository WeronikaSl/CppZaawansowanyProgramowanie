#pragma once
#include "Employee.hpp"
#include <vector>
#include <fstream>

class EmployeeWriterAbstract
{
public:
	virtual void writeToFile(std::vector<Employee> vec, std::ofstream& file) const = 0;
	virtual ~EmployeeWriterAbstract() = default;
};