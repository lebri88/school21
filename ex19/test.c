#include <stdio.h>

void	ft_swap(char *s1, char *s2)
{
	char *s3;

	printf("1 = %s, 2 = %s\n", s1, s2);
	s3 = &s1[0];
	s1 = &s2[0];
	s2 = &s3[0];
	printf("1 = %s, 2 = %s\n", s1, s2);
}

int	main(int argn, char **argv)
{
	if (argn < 1)
		return(100);
	ft_swap(argv[1], argv[2]);
	return(0);
}
