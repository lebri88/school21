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
		while (temp[i] != 0)
		{
				if (res[i] == 0 && temp[i] != 0)
						res[i] = '0';
				tmp = (temp[i] - '0') + (res[i] - '0') + ost;
				ost = tmp / 10 > 0 ? 1 : 0;
				res[i] = tmp % 10 + '0';
				i++;
				if (res[i] == 0 && ost == 1)
				{
						res[i] = '1';
						ost = 0;
				}
		}
}

/*
SPLIT ft_neg_pow on 2-3 ft somehow
*/

void	ft_neg_pow(char temp[310], int pow)
{

		int		i;
		int		ost;
		int		tmp;
		int		zero_ct;

		i = 309;
		while (i > 0)
				temp[i--] = 0;//ft_bzero;
		temp[i] = '1';
		ost = 0;
		zero_ct = 0;
		while (pow > 0)
		{
				while (temp[i] != 0)
				{
						tmp = (temp[i] - '0') * 5 + ost;
						ost = tmp / 10 > 0 ? (tmp / 10) : 0;
						temp[i] = tmp % 10 + '0';
						i++;
				}
				if (temp[i] == 0 && ost > 0)
				{
					temp[i] = ost + '0';
					ost = 0;
				}
				if (temp[i] == '1')
						zero_ct++;
				i = 0;
				pow--;
		}
		i = 0;
		while (temp[i] != 0)
				i++;
		while (zero_ct > 0)
		{
				temp[i] = '0';
				i++;
				zero_ct--;
		}
		temp[i] = '.';
		temp[i + 1] = '0';
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
		printf("\nbinary_to_dec = ");
		while (j >= 0)
				printf("%c", res[j--]);
		printf("\n");
		ft_neg_pow(temp, 15);			/*ft_negative_*/
		j = 0;
		while (temp[j] != 0)
				j++;
		printf("\nnegative_binary_to_dec = ");
		while (j >= 0)
				printf("%c", temp[j--]);
		printf("\n");
		return (0);
}

void ft_power_to_two(char temp[310], int pow)
{
		int		i;
		int		ost;
		int		tmp;

		i = 309;
		while (i > 0)
				temp[i--] = 0;
		temp[i] = '1';
		ost = 0;
		while (pow > 0)
		{
				while (temp[i] != 0)
				{
						tmp = (temp[i] - '0') * 2 + ost;
						ost = tmp / 10 > 0 ? 1 : 0;
						temp[i] = tmp % 10 + '0';
						i++;
				}
				if (temp[i] == 0 && ost == 1)
				{
					temp[i] = '1';
					ost = 0;
				}
				i = 0;
				pow--;
		}
}
