/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:29:24 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/21 14:38:13 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_delem
{
	int		num;
	char	*info;
}				t_delem;

t_delem			**ft_read_dico(char *filename);
void			ft_swap_dico(t_delem *elem1, t_delem *elem2);
void			ft_sort_dico(t_delem **dico);
int				ft_find_dico(t_delem **dico, int num);
int				ft_divisor(int nb);
int				ft_transform_num(int num);
void			ft_generate_dico(t_delem **dico, int num, int space, int done);

int				ft_divisor(int nb);
int				ft_transform_num(int num);
void			ft_write_dico(t_delem **dico, int id, int space);
void			ft_generate_auto(t_delem **dico, int nb, int space, int done);
char			ft_find_auto(t_delem **dico, int num, int space, int done);

unsigned int	ft_file_size(char *filename);
char			*ft_file_content(char *filename);

char			*ft_next_line(char *content);
int				ft_count_line(char *content);
t_delem			*ft_analyse_line(char *line);

char			ft_is_space(char c);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			ft_is_printable(char c);
char			*ft_strdup(char *src);
#endif
