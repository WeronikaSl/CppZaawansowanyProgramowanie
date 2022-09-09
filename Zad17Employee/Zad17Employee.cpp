#include "Employee.hpp"
#include "EmployeeManagerClass.hpp"
#include "EmployeeFileWriter.hpp"
#include <iostream>
#include <fstream>
#include <vector>


int main()
{

	EmployeeManager em;
	em.generateLogins();
	em.generatePasswords();
	for (const auto& x : em.getEmployees())
	{
		std::cout << x << std::endl;
	}

	std::string fileName = "C:\\Users\\Weronika Słowińska\\OneDrive\\Desktop\\CPP\\CppZaawansowaneProgramowanie\\Zad17Employee\\passwords.txt";
	std::ofstream fileTowrite(fileName, std::ios::app, std::ios::trunc);
	EmployeeFileWriter efw;
	efw.writeToFile(em.getEmployees(), fileTowrite);

}
