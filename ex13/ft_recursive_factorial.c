#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if ((nb <= 0) || (nb > 12))
		return(0);
	if (nb != 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	return(nb);
}

int	main(void)
{
	int a;
	int i;

	i = 13;
	while (i > -4)
	{
		a = ft_recursive_factorial(i);
		printf("i = %i a = %i\n", i, a);
		i--;
	}
	return(0);
}
