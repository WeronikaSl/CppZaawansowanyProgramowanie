#pragma once
#include "Employee.hpp"
#include "EmployeeReaderAbstractClass.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

class EmployeeFileReader : public EmployeeReaderAbstract
{
private:
	void isOpened(const std::ifstream& file) const;
	std::vector<std::string> readFromFile(std::ifstream& file) const;
public:
	std::vector<Employee> getEmployees(std::ifstream& file) const override;
};