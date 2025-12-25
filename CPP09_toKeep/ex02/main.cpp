
#include "PmergeMe.hpp"


int isValidInput(const std::string &input)
{
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]) && input[i] != ' ')
			return 0;
	}
	return 1;
}

std::vector<int> parse_sequence( std::string line )
{
	std::istringstream ss(line);
	
	std::vector<int>	result;
	
	double num;

	while (ss >> num)
	{
		if (num < 0 || num > 2147483647)
			throw std::out_of_range("Number out of int range");
		if (std::find(result.begin(), result.end(), num) != result.end())
			throw std::logic_error("Duplicate number ");

		result.push_back((int)num);	
	}
	if (result.empty())
		throw std::logic_error("No valid numbers provided");
	return result;
}

void	print_sequence( std::vector<int> &vec )
{
	static int turn = 0;

	if (turn++ == 0)
		std::cout << "Before: ";
	else
		std::cout << "After:  ";

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " sequence" << std::endl;
		return 1;
	}
	std::string	line = av[1];
	if (!isValidInput(line))
		return (std::cerr << "Error: Invalid input" << std::endl, 1);

	try
	{
		std::vector<int>	vec(parse_sequence(line));
		std::deque<int>		deq(vec.begin(), vec.end());

		print_sequence(vec);

		double	start_time = get_time_u();
		sort_vector(vec);
		double time_vector = get_time_u() - start_time;
		
		start_time = get_time_u();
		sort_deque(deq);
		double time_deque = get_time_u() - start_time;

		print_sequence(vec);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_vector << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << time_deque << " us" << std::endl;
	}
	catch (	std::exception &e)
	{
		std::cerr << "\nError: " << e.what() << std::endl;
		return 1;	
	}

	return 0;
}
