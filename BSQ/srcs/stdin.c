/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:19:04 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 18:53:48 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*stdin_alloc(char *content, int csize, char *part, int psize)
{
	char	*ncontent;
	int		a;
	int		b;

	if (!(ncontent = malloc(csize + psize)))
		return (NULL);
	a = 0;
	b = 0;
	if (csize)
		while (a < csize)
		{
			ncontent[a] = content[a];
			a++;
		}
	while (b < psize)
	{
		ncontent[a] = part[b];
		a++;
		b++;
	}
	free(content);
	return (ncontent);
}

char	*stdin_read(void)
{
	char	*content;
	char	tmp[32000];
	int		size;
	int		ret;

	content = NULL;
	size = 0;
	while ((ret = read(0, tmp, 32000)) > 0)
	{
		if (!(content = stdin_alloc(content, size, tmp, ret)))
			return (NULL);
		size += ret;
	}
	content[size] = '\0';
	return (content);
}
