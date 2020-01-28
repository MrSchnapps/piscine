/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:29:24 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/21 14:16:17 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	ft_file_size(char *filename)
{
	int		fd;
	char	buf[32000];
	int		size;
	int		len;

	size = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	while ((len = read(fd, buf, 32000)))
		size += len;
	if (close(fd))
		return (-1);
	return (size);
}

char			*ft_remove_empty(char *content, int size)
{
	int		a;
	int		b;
	char	*rcontent;

	a = 0;
	b = 0;
	if (!(rcontent = malloc(size)))
		return (NULL);
	while (a < size)
	{
		if (!(a && content[a] == '\n' && content[a - 1] == '\n'))
		{
			rcontent[b] = content[a];
			b++;
		}
		a++;
	}
	return (rcontent);
}

char			*ft_file_content(char *filename)
{
	int		fd;
	char	*content;
	char	*rcontent;
	int		size;
	int		len;

	size = ft_file_size(filename);
	if (size == -1 || !(content = malloc(size)))
		return (NULL);
	size = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	while ((len = read(fd, content + size, 32000)))
		size += len;
	if (close(fd))
		return (NULL);
	rcontent = ft_remove_empty(content, size);
	free(content);
	return (rcontent);
}
