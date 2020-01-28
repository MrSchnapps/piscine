/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:44:22 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/19 11:25:47 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_place_str(char *str, char *argvi, char **tab_str)
{
	int		ret;
	int		fd;
	int		i;
	char	buff[1];
	int		err;

	err = 0;
	fd = open(argvi, O_RDONLY);
	if ((err = errno))
		return (ft_printerr(err, tab_str, argvi));
	i = 0;
	while ((ret = read(fd, buff, 1)))
	{
		if ((err = errno))
			return (ft_printerr(err, tab_str, argvi));
		str[i++] = buff[0];
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

char	*ft_get_memory(char *str, char *argvi, unsigned int *cp, char **tab)
{
	unsigned int	cmpt;
	int				fd;
	char			buff[BUFF_SIZE];
	int				err;
	int				ret;

	cmpt = 0;
	err = 0;
	errno = 0;
	fd = open(argvi, O_RDONLY);
	if ((err = errno))
		return (ft_printerr(err, tab, argvi));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if ((err = errno))
			return (ft_printerr(err, tab, argvi));
		cmpt += ret;
		if (!(str = malloc((cmpt + 1) * sizeof(char))))
			return (0);
	}
	close(fd);
	*cp = cmpt;
	return (str);
}

void	ft_read_file(int argc, char **argv, unsigned int size, int i)
{
	unsigned int	cmpt_memory;
	char			*str;
	int				cmpt_error;
	int				cmpt_ok;

	cmpt_ok = 0;
	while (++i < argc)
	{
		cmpt_memory = 0;
		str = ft_get_memory(str, argv[i], &cmpt_memory, argv);
		if (str)
			str = ft_place_str(str, argv[i], argv);
		else
			cmpt_error = 1;
		if (str)
		{
			if (!(cmpt_error) || cmpt_ok > 0)
				ft_print_name(argc, i, 1, argv[i]);
			if (++cmpt_ok && argc > 4)
				ft_print_name(argc, i, 2, argv[i]);
			ft_print_tail(str, cmpt_memory, size);
			cmpt_error = 0;
		}
		free(str);
	}
}

int		ft_moderate_av(int argc, char **argv)
{
	unsigned int	size;
	int				i;

	i = 2;
	size = ft_atoi(argv[2]);
	if (argc == 3 && ft_str_is_numeric(argv[2]) == 1)
	{
		ft_print_stdin(size, argv);
		return (0);
	}
	if (argc >= 3 && !(ft_str_is_numeric(argv[2])))
	{
		write(2, "tail: illegal offset -- ", 25);
		ft_putstr(argv[2], 2);
		ft_putchar('\n');
		return (2);
	}
	if (argc >= 4)
		ft_read_file(argc, argv, size, i);
	return (0);
}

int		main(int argc, char **argv)
{
	int		ret;
	char	buff[BUFF_SIZE];

	while (argc == 1)
	{
		ret = read(0, buff, BUFF_SIZE);
		buff[ret] = '\0';
		ft_putstr(buff, 1);
	}
	if (argc == 2)
	{
		write(2, "usage: tail [-F | -f | -r] [-q] ", 32);
		write(2, "[-b # | -c # | -n #] [file ...]\n", 32);
		return (0);
	}
	if (argc > 2)
		ft_moderate_av(argc, argv);
	(void)argv;
	return (0);
}
