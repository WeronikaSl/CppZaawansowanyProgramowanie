#include "EmployeeFileReaderClass.hpp"

void EmployeeFileReader::isOpened(const std::ifstream& file) const 
{
	if (!file.is_open())
	{
		throw std::runtime_error("Nie można otworzyć pliku!");
	}
}

std::vector<std::string> EmployeeFileReader::readFromFile(std::ifstream file) const
{
	isOpened(file);
	std::vector<std::string> text = {};
	std::string lineInText = {};
	while (file.good() && !file.eof())
	{
		std::getline(file, lineInText);
		text.push_back(lineInText);
	}

	return text;
}
