
#include "shell.h"

int		ft_is_whitespace_or_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_find_end_of_token(int i, char *str, int *cont_read)
{
	while (str[i] != '\0' && str[i] != '\n' &&
		!ft_is_whitespace_or_tab(str[i]) && !ft_is_operator(&str[i]))
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '\'')
			i = ft_find_closing_single_quotes(i, str, cont_read);
		else if (str[i] == '"')
			i = ft_find_closing_double_quotes(i, str, cont_read);
		if (str[i] != '\0')
			i++;
	}
	return (i);
}

int		ft_check_end_of_token_position(char *str, int *io_nbr_flag, int *cont_read)
{
	int		i;

	i = 0;
	if (str[i] == '\n')
		while (str[i] == '\n')
			i++;
	else if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		ft_is_redirect_operator(&str[i]) > 0 ? *io_nbr_flag = 1 : ft_find_end_of_token(i, str, cont_read);
	}
	else if ((i = ft_is_operator(str)) > 0)
		return (i);
	else
		i = ft_find_end_of_token(i, str, cont_read);
	return (i);
}

int		ft_lexer_hub(char *str, t_list *data)
{
	int		i;
	int		io_nbr_flag;
	int		cont_read;
	t_list	*nextlist;

	cont_read = 0;
	i = 0;
	while (*str)
	{
		while (ft_is_whitespace_or_tab(*str))
			str++;
		io_nbr_flag = 0;
		i = ft_check_end_of_token_position(str, &io_nbr_flag, &cont_read);
		if (cont_read != 0)
			return (1);
		if (i != 0)
		{
			if (data->content)
			{
				nextlist = ft_lstnew(NULL, 0);
				data->next = nextlist;
				data = data->next;
			}
			ft_check_type_and_add_token(data, str, i, io_nbr_flag);
		}
		str = str + i;
	}
	return (0);
}

t_list	*lexer(char *line)
{
	t_list	*first;

	first = ft_lstnew(NULL, 0);
	if (ft_lexer_hub(line, first) == 1)
	{
		ft_printf("CONT_READ_PLS\n");
//		ft_delete_list		
		return (NULL);
	}
	
	t_token	*t;
	while (first)
	{
		t = first->content;
		ft_printf("%s\n", t->content);
//		ft_printf("%i\n", t->type);
		first = first->next;
	}
	return (first);
}
