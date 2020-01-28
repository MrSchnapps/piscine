/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:28:51 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/20 13:13:16 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_H
# define _FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# define BUFF_SIZE 32000

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str, int out);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
#endif
