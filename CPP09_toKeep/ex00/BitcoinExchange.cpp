
#include "BitcoinExchange.hpp"

void	storeData(std::map<std::string, double> &dataMap)
{
	std::ifstream	data("data.csv");
	if (!data.is_open())
		throw std::runtime_error("Failed to open data.csv");

	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		size_t spliter = line.find(',');

		std::string date = line.substr(0, spliter);
		double		value = std::atof(line.substr(spliter + 1).c_str());

		dataMap[date] = value;
	}
	data.close();
}

int		check_date(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad date format => " << date << std::endl;
		return 0;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2026 || month < 1 || month > 12)
	{
		std::cerr << "Error: bad date value => " << date << std::endl;
		return 0;
	}
	static const int mdays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > mdays[month - 1])
	{
		std::cerr << "Error: bad date value => " << date << std::endl;
		return 0;
	}
	return 1;
}

int		check_value(double value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (0);
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

int		valid_entry(std::string line)
{
	size_t spliter = line.find('|');
	if (spliter == std::string::npos || line[spliter - 1] != ' ' || line[spliter + 1] != ' ')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	if (spliter == 0 || spliter == line.length() - 1)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	std::string date = line.substr(0, spliter - 1);
	if (!check_date(date))
		return 0;
	
	double		value = std::atof(line.substr(spliter + 2).c_str());
	if (!check_value(value))
		return 0;

	return 1;
}

void	processInput(std::string filename, std::map<std::string, double> &map)
{
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open input file");

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		if (!valid_entry(line))
			continue;
		
		size_t 			spliter = line.find('|');
		std::string 	date = line.substr(0, spliter - 1);
		double			value = std::atof(line.substr(spliter + 2).c_str());
		
		std::map<std::string, double>::iterator it = map.lower_bound(date);
		if (it != map.end() && it->first == date)
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		else if (it != map.begin())
		{
			--it;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		else
			std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
	}
	
}