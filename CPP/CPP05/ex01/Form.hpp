
#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	
	public:

		Form(const std::string& name, const int gradeToSign, const int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned( const Bureaucrat &bcrat );

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};


};

std::ostream& operator<<(std::ostream& os, const Form& form);
