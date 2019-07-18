#include <unistd.h>

void	ft_print_alphabet(void)
{
	char z;

	z = 'a';
	while (z != ('z' + 1))
	{
		write(1, &z, 1);
		z++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print_alphabet();
	return(0);
}
