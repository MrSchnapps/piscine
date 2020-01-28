/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:35:26 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/20 09:36:41 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_printerr(int err, char **tab_str, char *argv)
{
	ft_putstr(basename(tab_str[0]), 2);
	ft_putstr(": ", 2);
	ft_putstr(argv, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(err), 2);
	ft_putstr("\n", 2);
	return (NULL);
}

void	ft_putstr_stdin(char *str, int cmpt)
{
	int i;

	i = 0;
	while (i < cmpt)
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_reassign(char *str, unsigned int cmpt, char *buff)
{
	unsigned int i;

	i = 0;
	while (i < cmpt)
	{
		str[i] = buff[i];
		i++;
	}
	return (str);
}

void	ft_printerr_stdin(int err, char **tab_str)
{
	ft_putstr(basename(tab_str[0]), 2);
	ft_putstr(": ", 2);
	ft_putstr("stdin: ", 2);
	ft_putstr(strerror(err), 2);
}

void	ft_print_stdin(unsigned int size, char **argv)
{
	int				ret;
	unsigned int	cmpt;
	char			buff[BUFF_SIZE];
	char			*str;
	int				err;

	cmpt = 0;
	err = 0;
	while ((ret = read(0, buff, BUFF_SIZE)))
	{
		if ((err = errno))
		{
			ft_printerr_stdin(err, argv);
			return ;
		}
		cmpt += ret;
		if (!(str = malloc((cmpt + 1))))
			return ;
		cmpt -= ret;
		ft_reassign(str + cmpt, ret, buff);
		cmpt += ret;
	}
	if (size > cmpt)
		size = cmpt;
	ft_putstr_stdin(str + cmpt - size, size);
}
