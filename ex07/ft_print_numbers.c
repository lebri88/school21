#include <unistd.h>

void	ft_print_numbers(void)
{
	int i;
	char z;

	i = 0;
	while (i < 10)
	{
		z = i + 48;
		write(1, &z, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print_numbers();
	return(0);
}
