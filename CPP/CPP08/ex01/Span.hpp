
#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class	Span
{
	private:
		unsigned int		N;
		std::vector<int>	vec;

	public:

		Span( unsigned int N);
		Span( const Span &other);
		Span &operator=( const Span &other);
		~Span();

		void	addNumber( int num);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};
