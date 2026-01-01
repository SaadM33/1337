
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
{
	private:
		
		const std::string	name;
		int					grade;

	public:
		
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &src );

		std::string	getName() const;
		int			getGrade() const;
		
		void		inc();
		void		dec();
		void		signForm(Form &form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char * what () const throw();
		
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char * what () const throw();
	};
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &src);


#endif