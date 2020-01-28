/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:21:08 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 18:53:58 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*str_nextline(char *content)
{
	int		len;
	int		a;
	char	*line;

	len = 0;
	while (content[len])
	{
		if (content[len] == '\n')
			break ;
		len++;
	}
	if (len <= 1)
		return (NULL);
	if (!(line = malloc(len + 1)))
		return (NULL);
	a = 0;
	while (a < len)
	{
		line[a] = content[a];
		a++;
	}
	line[a] = '\0';
	return (line);
}
