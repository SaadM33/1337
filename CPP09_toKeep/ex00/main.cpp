
#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>


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

int		check_date( std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad date format => " + date << std::endl;
		return (0);
	}
	int		year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > 2026)
	{
		std::cerr << "Error: bad date value => " + date << std::endl;
		return (0);
	}
	int		month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: bad date value => " + date << std::endl;
		return (0);
	}
	int		day = std::atoi(date.substr(8, 2).c_str());
	if (month == 2 && (day < 1 || day > 29))
	{
		std::cerr << "Error: bad date value => " + date << std::endl;
		return (0);
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
	{
		std::cerr << "Error: bad date value => " + date << std::endl;
		return (0);	
	}
	else if (day < 1 || day > 31)
	{
		std::cerr << "Error: bad date value => " + date << std::endl;
		return (0);
	}
	return (1);
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

void	processInput(std::string filename, std::map<std::string, double> &date_to_rate)
{
	std::ifstream	inputFile(filename);
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open input file");

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		size_t spliter = line.find('|');
		if (spliter == std::string::npos || line[spliter - 1] != ' ' || line[spliter + 1] != ' ')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (spliter == 0 || spliter == line.length() - 1)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, spliter - 1);
		if (!check_date(date))
			continue;
		
		double		value = std::atof(line.substr(spliter + 2).c_str());
		if (!check_value(value))
			continue;

		std::map<std::string, double>::iterator it = date_to_rate.lower_bound(date);
		

		
			

	}
	
}	

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return 1;
	}
	
	std::map<std::string, double> date_to_rate;

	try
	{
		storeData(date_to_rate);
		processInput(av[1], date_to_rate);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
