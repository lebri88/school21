#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int i;
	int k;
	int *range;

	if ((max - min) <= 0)
	{
		range = NULL;
		return(range);
	}
	k = max - min;
	range = malloc(sizeof(int) * k);
	i = 0;
	while (i != k)
	{
		range[i] = min;
		min++;
		i++;
	}
	return(range);
}

int	main(void)
{
	int min;
	int max;
	int *range;
	int i;

	i = 0;
	min = 20;
	max = 10;
	printf("min = %i, max = %i, range = ", min, max);
	range = ft_range(min, max);
//	while (range[i])
//	{
//		printf("%i, ", range[i]);
//		i++;
//	}
//	printf("\n");
	return(0);
}
