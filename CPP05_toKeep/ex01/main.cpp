
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try 
	{
		Bureaucrat a("fueh", -3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception during creation: " << e.what() << std::endl << std::endl;
	}

	Bureaucrat b("Akhenouch", 90);
	Form f("Form", 45, 100);

	b.signForm(f);

}