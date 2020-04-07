#include "shell.h"

int		ft_find_closing_single_quotes(int i, char *str, int *cont_read)
{
	i++;
	while (str[i] != '\0' && str[i] != '\'')
		i++;
	if (str[i] != '\'')
		*cont_read = 1;
	return (i);
}

int		ft_find_closing_double_quotes(int i, char *str, int *cont_read)
{
	i++;
	while (str[i] != '\0' && str[i] != '"')
		i++;
	if (str[i] == '\0')
		*cont_read = 1;
	return (i);
}
