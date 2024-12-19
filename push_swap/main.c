
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	int temp;

	i = 1;
	if (argc >= 2)
	{
		while(argv[i])
		{
			temp = ft_atoi(argv[i]);
			printf("%d\n", temp);
			i++;
		}
	}
}