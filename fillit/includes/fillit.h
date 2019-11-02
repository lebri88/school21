/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:25:34 by geliz             #+#    #+#             */
/*   Updated: 2019/11/01 19:36:40 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
int		main(int argn, char **argv);
int		ft_readfile(char *file, t_list *first);
int		ft_hub(char *buf, t_list *first);
int		ft_validate_lines(char *buf);
int		ft_check_newlines(char *buf);
int		ft_check_symbols(char *buf);
int		ft_check_figure(char *buf);
void	ft_cleanlist(t_list *first);
char	**ft_cutstring(char *buf);
/*char	**ft_clean_strings(char **temp);
char	**ft_clean_cols(char **temp);
char	**ft_copy_arr(char **temp);
void	ft_free_arr(char **arr);*/
# include <stdio.h>
#endif
