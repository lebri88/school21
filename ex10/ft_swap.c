#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int a;
	int b;
	int *ptr;
	int *ptr2;

	a = -5;
	b = 155;
	printf("a = %i b = %i\n", a, b);
	ptr = &a;
	ptr2 = &b;
	ft_swap(ptr, ptr2);
	printf("a = %i b = %i\n", a, b);
	return(0);
}
