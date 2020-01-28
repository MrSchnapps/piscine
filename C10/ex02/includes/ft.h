/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:28:51 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/18 20:42:05 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_H
# define _FT_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <libgen.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 32768

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str, int out);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_str_is_numeric(char *str);
int		ft_atoi(char *str);
char	*ft_reassign(char *str, unsigned int cmpt, char *buff);
void	ft_printerr_stdin(int err, char **tab_str);
void	ft_print_stdin(unsigned int size, char **argv);
char	*ft_printerr(int err, char **tab_str, char *argv);
void	ft_print_name(int argc, int i, int choice, char *avi);
void	ft_print_tail(char *str, unsigned int cmpt_memory, unsigned int size);
#endif
