#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while ((i * i) <= nb)
	{
		if ((i * i) == nb)
			return(i);
		i++;
	}
	return(0);
}

int	ft_atoi(char *arr)
{
	int i;
	int sign;
	int nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	if (arr[i] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (arr[i] != '\0')
	{
		nbr = nbr * 10 + (arr[i] -'0');
		i++;
	}
	nbr = nbr * sign;
	return(nbr);
}

int	main(int argn, char **argv)
{
	int z;
	int res;
	int i;

	i = 1;
	if (argn < 0)
		return(9);
	while (i < argn)
	{
		z = ft_atoi(argv[i]);
		res = ft_sqrt(z);
		printf("number = %i, sqrt = %i\n", z, res);
		i++;
	}
	return(0);
}
