#pragma once
#include "Employee.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

class EmployeeFileReader
{
private:
	void isOpened(const std::ifstream& file) const;
	std::vector<std::string> readFromFile(std::ifstream& file) const;
	//void setDataMembers();
public:
	std::vector<Employee> getEmployees(std::ifstream& file) const;
};