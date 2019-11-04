/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:31:25 by geliz             #+#    #+#             */
/*   Updated: 2019/11/04 14:48:01 by geliz            ###   ########.fr       */
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
	if (ret == 0)					  //delete it later
		printf("VALIDATION FAILED\n");//temp
	if (ret != 0)						//
		ft_check_list(first);			//
	ret = ft_fill_map(first);
	ft_clean_list(first);
	return (ret);
}
