
#include "BitcoinExchange.hpp"

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
