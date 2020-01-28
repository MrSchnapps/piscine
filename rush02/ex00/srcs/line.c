/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:29:24 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/21 14:37:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_next_line(char *content)
{
	int		a;
	int		size;
	char	*line;

	a = 0;
	size = 1;
	while (content[a] != '\n' && content[a] != '\0')
	{
		size++;
		a++;
	}
	if (!a)
		return (NULL);
	if (!(line = malloc(size)))
		return (NULL);
	a = 0;
	while (content[a] != '\n' && content[a] != '\0')
	{
		line[a] = content[a];
		a++;
	}
	line[a] = '\0';
	return (line);
}

int			ft_count_line(char *content)
{
	char	*line;
	int		size;
	int		linecount;

	size = 0;
	linecount = 0;
	while ((line = ft_next_line(content + size)))
	{
		size += ft_strlen(line) + 1;
		linecount++;
		free(line);
	}
	return (linecount);
}

t_delem		*ft_analyse_line(char *line)
{
	t_delem		*elem;
	int			num;
	char		*info;

	num = 0;
	while (*line >= '0' && *line <= '9')
	{
		num = num * 10 + (*line - '0');
		line++;
	}
	while (*line == ' ')
		line++;
	if (*line != ':')
		return (NULL);
	line++;
	while (*line == ' ')
		line++;
	if (!(info = ft_strdup(line)))
		return (NULL);
	if (!(elem = malloc(sizeof(t_delem))))
		return (NULL);
	elem->num = num;
	elem->info = info;
	return (elem);
}
