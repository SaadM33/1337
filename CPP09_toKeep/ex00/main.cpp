
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

void	processInput(std::string filename, std::map<std::string, double> &date_to_rate)
{
	std::ifstream	inputFile(filename);
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open input file");

	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		
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
