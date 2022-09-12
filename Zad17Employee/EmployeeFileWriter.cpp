#include "EmployeeFileWriter.hpp"

void EmployeeFileWriter::isOpened(const std::ofstream& file) const
{
	if (!file.is_open())
	{
		throw std::runtime_error("Nie można otworzyć pliku!");
	}
}


std::vector<std::string> EmployeeFileWriter::getDataForPasswordsFile(std::vector<Employee> vec) const
{
	std::vector<std::string> data = {};
	std::stringstream ss;

	auto lambda = [&](Employee employee)
	{
		ss << employee.getLogin() << ","
			<< employee.getEmail() << ","
			<< employee.getPassword() << "\n";

		data.push_back(ss.str());
		ss.str(std::string());
	};
	std::for_each(vec.cbegin(), vec.cend(), lambda);

	return data;
}

void EmployeeFileWriter::writeToFile(std::vector<Employee> vec, std::ofstream& file) const
{
	std::vector<std::string> text = getDataForPasswordsFile(vec);

	isOpened(file);
	for (auto it = text.cbegin(); it < text.cend(); ++it)
	{
		if (file.good())
		{
			file << *it;
		}
	}
	file.close();
}
