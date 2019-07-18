#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char *dest;
	int i;
	int k;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	k = 0;
	while (k != (i + 1))
	{
		dest[k] = src[k];
		k++;
	}
	return(dest);
}

int	main(int argn, char **argv)
{
	int i;
	char *res;
	
	i = 1;
	if (argn < 0)
		return(999);
	while (i < 5)
	{
		printf("%i circle === src str = %s-----", i, argv[i]);
		res = ft_strdup(argv[i]);
		printf("cpied str = %s\n", res);
		i++;
	}
	return(0);
}
