#include "EmployeeManagerClass.hpp"

std::vector<Employee> EmployeeManager::createVecOfEmployees(std::vector<std::string> v) 
{
	std::vector<Employee> vecOfEmployees = {};

	auto lambda = [&](std::string line)
	{
		//uzyc getline
	};
	std::for_each(v.begin(), v.end(), lambda);
}

EmployeeManager::EmployeeManager(std::ifstream& file)
{

}
