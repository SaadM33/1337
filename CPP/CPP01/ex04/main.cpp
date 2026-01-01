
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::ifstream	file(av[1]);
	if (!file)
	{
		perror("Error");
		return 1;
	}

	std::ofstream	outFile((std::string(av[1]) + ".replace").c_str());
	if (!outFile)
	{
		perror("Error");
		return 1;
	}

	std::string line;
	while (std::getline(file, line))
	{
		size_t	pos = 0;
		while (1)
		{
			pos = line.find(av[2], pos);
			if (pos == std::string::npos)
				break ;
			std::cout << "Found at position: " << pos << std::endl;
			line.erase(pos, std::string(av[2]).size());
			line.insert(pos, av[3]);
			pos += std::string(av[3]).size();
		}
		outFile << line;
		if (!file.eof())
			outFile << std::endl;

	}

	return 0;
}