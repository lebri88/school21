#include <unistd.h>

void	ft_putstr(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
		write (1, &arr[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	ft_printmas(char **arr)
{
	int i;

	i = 1;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		i++;
	}
}

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

void	ft_sort(int n, char **arr)
{
	int i;
	int k;
	int cmp;
	char *s3;

	i = 1;
	k = 1;
	while (i < n)
	{
		while (arr[k])
		{
			cmp = ft_strcmp(arr[i], arr[k]);
			if (cmp < 0)
			{
				s3 = arr[i];
				arr[i] = arr[k];
				arr[k] = s3;
			}
			k++;
		}
		k = 1;
		i++;
	}
	ft_printmas(arr);
}

int	main(int argn, char **argv)
{
	ft_sort(argn, argv);
	return(0);
}
