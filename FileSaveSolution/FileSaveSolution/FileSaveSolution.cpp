#include "FileWriter.h"
#include <iostream>



int main()
{
    std::string name;
    std::string surname;
    int age;

    std::cout << "Enter Name: ";
    std::cin >> name;

    std::cout << "Enter Surname: ";
    std::cin >> surname;

    std::cout << "Enter Age: ";
    std::cin >> age;

    FileWriterr(name, surname, age);
	return 0;
}

