
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cmath>

class ScalarConverter
{
	private:
	
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter& operator=( const ScalarConverter& other );

	public:
	
		static void		convert( std::string literal );

};