/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:31:25 by geliz             #+#    #+#             */
/*   Updated: 2019/11/03 17:58:31 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_list(t_list *first)
{
	t_list	*temp;
	char	**arr;

	temp = first;
	while (temp)
	{
		printf("%c\n", (char)temp->content_size);
		arr = temp->content;
		while (*arr)
		{
			printf("%s\n", *arr);
			arr++;
		}
		printf("\n");
		temp = temp->next;
	}

}

int		main(int argn, char **argv)
{
	t_list	*first;
	int		ret;

	if (argn != 2)
	{
		write(1, "arguments error\n", 16);
		return (0);
	}
	if (!(first = ft_lstnew(NULL, 0)))
		return (0);
	ret = ft_readfile(argv[1], first);
//	if (ret == 0 && first != NULL)
//		ft_clean_list(first);
	if (ret == 0)
		printf("VALIDATION FAILED\n");
	ft_check_list(first);
	ft_clean_list(first);
	return (ret);
}
