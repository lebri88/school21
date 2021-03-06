/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:25:34 by geliz             #+#    #+#             */
/*   Updated: 2019/11/22 16:40:41 by geliz            ###   ########.fr       */
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
void	ft_clean_list(t_list *first);
void	ft_free_array(char **arr);
int		ft_fill_content_size(t_list *first);
int		ft_fill_map(t_list *first);
int		ft_count_side_size(t_list *first);
void	ft_change_symbol(char **arr, char c);
int		ft_create_map(int side, t_list *first);
int		ft_first_tetr_iter(int s, char map[s][s], t_list *first);
int		ft_place_tetr_hub(int s, char map[s][s], t_list *first, int tmp[2]);
int		ft_print_map(int s, char map[s][s]);
void	ft_map_copy(int s, char map[s][s], char temp[s][s]);
int		ft_opportunity(int s, char map[s][s], int crd[2], t_list *temp);
int		ft_check_op(int s, char map[s][s], int crd[2], char **str);
void	ft_paint_map(int s, char map[s][s], int crd[2], char **str);
#endif
