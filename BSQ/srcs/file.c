/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:16:36 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 18:53:20 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		file_open(char *filename)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	return (fd);
}

int		file_rewind(char *filename, int fd)
{
	if (close(fd))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	return (fd);
}

int		file_size(int fd)
{
	char	tmp[32000];
	int		ret;
	int		size;

	size = 0;
	while ((ret = read(fd, tmp, 32000)) > 0)
		size += ret;
	return (size);
}

char	*file_read(char *filename, int fd)
{
	char	*content;
	int		ret;
	int		size;

	if (!(content = malloc(file_size(fd) + 1)))
		return (NULL);
	if ((fd = file_rewind(filename, fd)) == -1)
		return (NULL);
	size = 0;
	while ((ret = read(fd, content + size, 32000)) > 0)
		size += ret;
	content[size] = '\0';
	return (content);
}

char	*file_read_content(char *filename)
{
	int fd;

	if (filename)
	{
		if ((fd = file_open(filename)) == -1)
			return (NULL);
		return (file_read(filename, fd));
	}
	else
		return (stdin_read());
	return (NULL);
}
