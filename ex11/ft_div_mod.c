#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int a; 
	int b;
	int divi;
	int modi;
	int *div;
	int *mod;

	a = 22;
	b = 4;
	div = &divi;
	mod = &modi;
	ft_div_mod(a, b, div, mod);
	printf("div = %i mod = %i\n", divi, modi);
	return(0);
}
