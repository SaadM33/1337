
#pragma once

#include <deque>
#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack( const MutantStack &other ) : std::stack<T>( other ) {}
		MutantStack &operator=( const MutantStack &other )
		{
			if (this != &other )
				std::stack<T>::operator=( other );
			return *this;
		}
		~MutantStack() {}

		

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}


		iterator end()
		{
			return this->c.end();
		}


		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		const_iterator cbegin() const
		{
			return this->c.cbegin();
		}


		const_iterator cend() const
		{
			return this->c.cend();
		}



};