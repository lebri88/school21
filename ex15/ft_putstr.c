#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argn, char **argv)
{
	int i;

	i = 1;
	while(i != argn)
	{
		ft_putstr(argv[i]);
		i++;
		write(1, "\n", 1);
	}
	return(0);
}
