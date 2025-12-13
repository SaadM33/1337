
#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	
	mstack.pop();

	std::cout << mstack.size() << std::endl;

	std::cout << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();


	std::cout << "Iterating through MutantStack elements:" << std::endl;
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}


	std::cout << "---- Copying MutantStack into another ----" << std::endl;
	MutantStack<int> s2(mstack);

	for ( MutantStack<int>::iterator it2 = s2.end() - 1 ; it2 != s2.begin() - 1; --it2)
	{
		std::cout << *it2 << std::endl;
	}


	return 0;
}