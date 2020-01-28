/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:34:20 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/20 14:16:48 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_printerr(int err, char **argv, char *argvi)
{
	ft_putstr(basename(argv[0]), 2);
	ft_putstr(": ", 2);
	ft_putstr(argvi, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(err), 2);
	ft_putstr("\n", 2);
}

void	ft_print_file(int fd, char **argv, char *argvi)
{
	char	buff[BUFF_SIZE];
	int		ret;
	int		err;

	err = 0;
	errno = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if ((err = errno))
		{
			ft_printerr(err, argv, argvi);
			return ;
		}
		write(1, buff, ret);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		i;
	int		err;
	char	buff[BUFF_SIZE];

	i = 1;
	if (argc < 2 || argv[1][0] == '-')
	{
		while ((ret = read(0, buff, BUFF_SIZE)))
			write(1, buff, ret);
	}
	while (i < argc)
	{
		err = 0;
		errno = 0;
		fd = open(argv[i], O_RDONLY);
		if ((err = errno))
			ft_printerr(err, argv, argv[i]);
		else
			ft_print_file(fd, argv, argv[i]);
		close(fd);
		i++;
	}
	return (0);
}
