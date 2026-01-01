

#include "RPN.hpp"

int		isValidRPN(const std::string &line)
{
	int		numbers = 0;
	int		operators = 0;

	for (size_t i = 0; i < line.length(); ++i)
	{
		if ( std::isdigit(line[i]) && atoi(&line[i]) >= 0 )
			numbers++;
		else if (strchr("+-*/", line[i]))
			operators++;
		else if (line[i] == ' ')
			continue;
		else
			return 0;
	}
	return (numbers == operators + 1);
}

int		evaluateRPN(const std::string line)
{
	std::stack<int> stack;

	for (size_t i = 0; i < line.length(); ++i)
	{
		if (std::isdigit(line[i]))
			stack.push(atoi(&line[i]));
		else if (line[i] == ' ')
			continue;
		else
		{
			if (stack.size() < 2)
				throw std::runtime_error("Insufficient operands");
		
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			int result;
			if (line[i] == '+')
				result = a + b;
			else if (line[i] == '-')
				result = a - b;
			else if (line[i] == '*')
				result = a * b;
			else if (line[i] == '/')
			{
				if ( b == 0)
					throw std::runtime_error("Division by zero");
				result = a / b;
			}

			stack.push(result);
		}
	}
	return stack.top();
}