
#include "Span.hpp"


Span::Span( unsigned int N)
{
	this->N = N;
	this->vec.reserve(N);
}

Span::Span( const Span &other)
{
	this->N = other.N;
	this->vec = other.vec;
}

Span &Span::operator=( const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->vec = other.vec;
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber( int num)
{
	if ( this->vec.size() >= this->N)
		throw std::out_of_range("Vector is full");
	this->vec.push_back(num);
}

int	Span::shortestSpan()
{
	int	min_span = 2000000;

	if (this->vec.size() < 2)
		throw std::runtime_error("vector is too small");

	for (size_t i = 0 ; i < this->vec.size(); ++i)
	{
		for (size_t j = 0 ; j < this->vec.size(); ++j)
		{
			if (i == j)
				continue;
			int tmp_span = abs(this->vec[i] - this->vec[j]);
			if (tmp_span < min_span)
				min_span = tmp_span;
		}
	}
	return min_span;
}

int	Span::longestSpan()
{
	if ( this->vec.size() < 2)
		throw std::out_of_range("vector is too small");

	int	max = *std::max_element(this->vec.begin(), this->vec.end());
	int	min = *std::min_element(this->vec.begin(), this->vec.end());
	
	return max - min;
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int	range_size = std::distance(begin, end);

	if ( this->vec.size() + range_size > this->N)
		throw std::runtime_error("Vector will exceed its limit");

	this->vec.insert(this->vec.end(), begin, end);
}
