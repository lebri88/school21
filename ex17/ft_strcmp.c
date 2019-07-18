#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int res;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	res = s1[i] - s2[i];
	return(res);
}

int	main(int argn, char **argv)
{
	int my;
	int tru;

	if (argn == 0)
		return(9);
	my = ft_strcmp(argv[1], argv[2]);
	tru = strcmp(argv[1], argv[2]);
	printf("my = %i, tru = %i\n", my, tru);
	return(0);
}
