/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:05:18 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/18 23:13:56 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		while ((ret = read(fd, buff, BUFF_SIZE)))
			write(1, buff, ret);
		if (close(fd))
			return (1);
	}
	return (0);
}
