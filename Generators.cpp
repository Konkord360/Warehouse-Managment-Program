#include "Generators.h"
#include <random>
#include <string>
#include <ctime>
std::string IDGenerator::generate()
{
	std::string IDnumber;
	std::random_device rd; 
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> numberGen(1000, 9999);
	std::uniform_int_distribution<> character(65, 90);

	long number = numberGen(eng);
	IDnumber = std::to_string(number);
	IDnumber += character(eng);
	IDnumber += character(eng);
	IDnumber += character(eng);
	return IDnumber;
}

std::string ExpirationDateGenerator::generate()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> newDayGen(1, 28);
	std::uniform_int_distribution<> newMonthGen(1, 12);
	std::uniform_int_distribution<> plusYearGen(1, 10);
	long newDay, newMont, plusYears;

	std::string finalDate="",day="",month="",year="",date = "";
	std::time_t t = std::time(0);

	date = ctime(&t);

	newDay = newDayGen(eng);
	newMont = newMonthGen(eng);
	plusYears = plusYearGen(eng);

	day = std::to_string(newDay);

	if (day.size() == 1)
		day = '0' + day;

	month = std::to_string(newMont);

	if (month.size() == 1)
		month = '0' + month;

	year = date.substr(20, 4);
	year = std::to_string(std::stoi(year) + plusYears);

	finalDate = day + "." + month + "." + year;
	return finalDate;
}
