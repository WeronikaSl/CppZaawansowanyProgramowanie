#include "Employee.hpp"
#include "EmployeeManagerClass.hpp"
#include "EmployeeFileWriter.hpp"
#include "EmployeeFileReaderClass.hpp"
#include "EmployeeReaderAbstractClass.hpp"
#include "EmployeeWriterAbstractClass.hpp"
#include "EmployeeFileJSONWriter.hpp"
#include "EmployeeJSONWriterPasswordsClass.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using json = nlohmann::json;


int main()
{
	try {
		std::shared_ptr<EmployeeReaderAbstract> polyPointerReader;
		polyPointerReader = std::make_shared<EmployeeFileReader>();

		std::ifstream file("employee_input.csv");
		EmployeeManager em(polyPointerReader->getEmployees(file));


		em.generateLogins();
		em.generatePasswords();


		for (const auto& x : em.getEmployees())
		{
			std::cout << x << std::endl;
		}

		std::shared_ptr<EmployeeWriterAbstract> polyPointerWriter;
		polyPointerWriter = std::make_shared<EmployeeFileWriter>();

		std::string fileName = "C:\\Users\\Weronika Słowińska\\OneDrive\\Desktop\\CPP\\CppZaawansowaneProgramowanie\\Zad17Employee\\passwords.txt";
		std::ofstream fileTowrite(fileName, std::ios::out, std::ios::trunc);

		polyPointerWriter->writeToFile(em.getEmployees(), fileTowrite);

		//std::ofstream o("Employees.json");
		//EmployeeWriterJSON writer;
		//writer.writeToFile(em.getEmployees(), o);

		std::ofstream os("Passwords.json");
		EmployeeJSONWriterPasswords passwords;
		passwords.writeToFile(em.getEmployees(), os);
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
}
