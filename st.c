#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_power_to_two(char temp[310], int pow);

void	ft_summ_strings(char res[310], char temp[310])
{
		int		i;
		int		tmp;
		int		ost;

		i = 0;
		ost = 0;
		i = 310;
		printf("res = ");
		while (i > -1)	
				printf("%c", res[i--]);
		printf("\ntemp = ");
		i = 310;
		while (i > -1)
				printf("%c", temp[i--]);
		printf("\n");
		i = 0;
		while (temp[i] != 0)
		{
				if (res[i] == 0 && temp[i] != 0)
						res[i] = '0';
				tmp = (temp[i] - '0') + (res[i] - '0') + ost;
				if (ost == 1)
						ost = 0;
				if (tmp / 10 > 0)
						ost = 1;
				res[i] = tmp % 10 + '0';
				i++;
				if (res[i] == 0 && ost == 1)
				{
						res[i] = '1';
						ost = 0;
				}
		}
		/*	while (res[i] != 0)
			i++;
			while (i >= 0)
			printf("%c", res[--i]);*/
}

void	ft_neg_pow(char temp[310], int pow)
{

		int		i;
		int		ost;
		int		fut_ost;
		int		tmp;

		i = 309;
		while (i > 0)
				temp[i--] = 0;//ft_bzero;
		temp[i] = '1';
		ost = 0;
		fut_ost = 0;
		write(1, "HERE", 4);
		while (pow > 0)
		{
				while (temp[i] != 0)
				{
						if (fut_ost != 0)
						{
								ost = fut_ost;
								fut_ost = 0;
						}
						tmp = temp[i] - '0';
						tmp = tmp * 5 + ost;
						if (tmp / 10 > 0)
								fut_ost = tmp / 10;
						temp[i] = tmp % 10 + '0';
						ost = 0;
						i++;
				}
				if (temp[i] == 0 && fut_ost != 0)
				{
						temp[i] = fut_ost + '0';
						fut_ost = 0;
				}
				pow--;
				i = 0;
		}
		i = 0;
		while (i < 10)
				printf("%c", temp[i++]);
}
/*
EACH TIME FIRST NUMBER OF SQUARE 5 IS 1 (CANNOT BE DELETED TO 2 W/O PROBLEMS) 0.0 is added to final nbr!
*/

int	main(int argn, char **argv)
{
		char	*str;
		int		pow;
		int		j;
		char	res[310];
		char	temp[310];

		if (argn != 2)
		{
				printf("NEED MORE ARGS\n");
				return (0);
		}
		pow = 0;
		str = argv[1];
		j = 0;
		while (j < 310)
				res[j++] = 0;
		j = strlen(str) - 1;
		//	ft_power_to_two(temp, 23);
		while (j >= 0)
		{
				if (str[j] == '1')
				{
						//			write(1, "@@", 2);
						ft_power_to_two(temp, pow);
						ft_summ_strings(res, temp);
				}
				j--;
				pow++;
		}
		j = 0;
		while (res[j] != 0)
				j++;
		while (j >= 0)
				printf("%c", res[j--]);
		printf("\n");
		ft_neg_pow(temp, 4);
		j = 0;
		while (temp[j] != 0)
				j++;
		while (j >= 0)
				printf("%c", res[j--]);
		printf("\n");
		return (0);
}

void ft_power_to_two(char temp[310], int pow)
{
		int		i;
		int		ost;
		int		fut_ost;
		int		tmp;

		i = 309;
		while (i > 0)
				temp[i--] = 0;//ft_bzero;
		temp[i] = '1';
		ost = 0;
		fut_ost = 0;
		while (pow > 0)
		{
				while (temp[i] != 0)
				{
						if (fut_ost == 1)
						{
								ost = 1;
								fut_ost = 0;
						}
						tmp = temp[i] - '0';
						tmp = tmp * 2 + ost;
						if (tmp / 10 > 0)
								fut_ost = 1;
						temp[i] = tmp % 10 + '0';
						ost = 0;
						i++;
				}
				if (temp[i] == 0 && fut_ost == 1)
				{
						temp[i] = '1';
						fut_ost = 0;
				}
				pow--;
				i = 0;
		}
		/*	while (temp[i] != 0)
			i++;
			while (i >= 0)
			printf("%c", temp[--i]);
			printf("\n");*/
}
