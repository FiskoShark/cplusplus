#include "pch.h"
#include "FileWriter.h";

#include <fstream>
#include <iostream>


std::string fileName = "data.txt";

void FileWriterr(std::string name, std::string surname, int age)
{
	std::ofstream file(fileName, std::ios::app);

	if (file.is_open())
	{
		file << name << " " << surname << " " << age << std::endl;
		file.close();
		std::cout << "Data successfully saved to " << fileName << std::endl;
	}

	else
	{
		std::cout << "Failed to open file." << std::endl;
	}
}
