/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:25:34 by geliz             #+#    #+#             */
/*   Updated: 2019/11/04 19:27:19 by geliz            ###   ########.fr       */
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
void	ft_create_arr(char temp[4][5], char *buf);
void	ft_clean_cols(char temp[4][5]);
void	ft_clean_strings(char temp[4][5]);
char	**ft_create_tetr(char temp[4][5]);
size_t	ft_count_symbols(char temp[4][5]);
char	*ft_create_string(char temp[4][5], char *str);
int		ft_fill_list(char **split, t_list *first);
void	ft_clean_list(t_list *first);//proverit'
void	ft_free_array(char **arr);//proverit'
void	ft_fill_content_size(t_list *first);
void	ft_check_list(t_list *first);//vremennaja ft
int		ft_fill_map(t_list *first);
int		ft_count_side_size(t_list *first);
//char	**ft_create_map(int size);
int		ft_place_tetr_hub(int s, char map[s][s], t_list *first, int x, int y);
//int		ft_place_tetr(cha
# include <stdio.h>
#endif
