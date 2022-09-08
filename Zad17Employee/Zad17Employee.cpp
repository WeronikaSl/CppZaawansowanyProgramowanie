#include "Employee.hpp"
#include "EmployeeManagerClass.hpp"
#include <iostream>
#include <fstream>
#include <vector>


int main()
{
	EmployeeManager em;
	em.generateLogin();
	for (const auto& x : em.getEmployees())
	{
		std::cout << x << std::endl;
	}





}
