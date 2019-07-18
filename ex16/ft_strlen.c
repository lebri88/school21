#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int	main(int argn, char **argv)
{
	int my;
	int tru;

	if (argn == 0)
		return(0);
	my = ft_strlen(argv[1]);
	tru = strlen(argv[1]);
	printf("my = %i, strlen = %i\n", my, tru);
	return (0);	
}
