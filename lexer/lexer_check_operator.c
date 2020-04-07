#include "shell.h"

int		ft_is_operator(char *str)
{
	if (!ft_strncmp(str, "<<-", 3))
		return (3);
	if (!ft_strncmp(str, ";;", 2) || !ft_strncmp(str, ">>", 2)
		|| !ft_strncmp(str, "<<", 2) || !ft_strncmp(str, ">&", 2)
		|| !ft_strncmp(str, "<&", 2) || !ft_strncmp(str, "||", 2)
		|| !ft_strncmp(str, "&&", 2) || !ft_strncmp(str, "<>", 2)
		|| !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '|' || *str == ';' || *str == '>' || *str == '<' || *str == '&'
            || *str == '(' || *str == ')')
		return (1);
	else
		return (0);
}

int		ft_is_redirect_operator(char *str)
{
	if (!ft_strncmp(str, "<<-", 3))
		return (3);
	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<<", 2)
		|| !ft_strncmp(str, "<&", 2) || !ft_strncmp(str, ">&", 2)
		|| !ft_strncmp(str, "<>", 2) || !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '>' || *str == '<')
		return (1);
	else
		return (0);
}