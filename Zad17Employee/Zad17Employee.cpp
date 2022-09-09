#include "Employee.hpp"
#include "EmployeeManagerClass.hpp"
#include "EmployeeFileWriter.hpp"
#include "EmployeeFileReaderClass.hpp"
#include "EmployeeReaderAbstractClass.hpp"
#include "EmployeeWriterAbstractClass.hpp"
#include <iostream>
#include <fstream>
#include <vector>


int main()
{
	std::shared_ptr<EmployeeReaderAbstract> polyPointerReader;
	polyPointerReader = std::make_shared<EmployeeFileReader>(); //bedzie mozna zmienic na JSON

	std::ifstream file("employee_input.csv");
	EmployeeManager em(polyPointerReader->getEmployees(file));


	em.generateLogins();
	em.generatePasswords();


	for (const auto& x : em.getEmployees())
	{
		std::cout << x << std::endl;
	}

	std::shared_ptr<EmployeeWriterAbstract> polyPointerWriter;
	polyPointerWriter = std::make_shared<EmployeeFileWriter>(); //bedzie mozna zmienic na JSON

	std::string fileName = "C:\\Users\\Weronika Słowińska\\OneDrive\\Desktop\\CPP\\CppZaawansowaneProgramowanie\\Zad17Employee\\passwords.txt";
	std::ofstream fileTowrite(fileName, std::ios::out, std::ios::trunc);

	std::vector<std::string> textToFile = em.getDataForPasswordsFile();

	polyPointerWriter->writeToFile(textToFile, fileTowrite);

}
