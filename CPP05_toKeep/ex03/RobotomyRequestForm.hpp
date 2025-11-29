
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>
// #include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		
		std::string target;
	
	public:

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	execute( const Bureaucrat & executor ) const;
};
