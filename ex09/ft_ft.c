#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int *nbr;
	int a;

	a = 0;
	printf("%i\n", a);
	nbr = &a;
	ft_ft(nbr);
	printf("%i\n", a);
	return(0);
}
