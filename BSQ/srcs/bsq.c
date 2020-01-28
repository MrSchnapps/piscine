/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:14:28 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 18:49:15 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	bsq_read_firstline(t_bsq bsq, char *line, char *content)
{
	int		len;

	if ((len = nt_strlen(line)) < 4)
		return (bsq);
	bsq.full = line[len - 1];
	bsq.obstacle = line[len - 2];
	bsq.empty = line[len - 3];
	bsq.lines_size = -1;
	line[len - 3] = '\0';
	bsq.lines_count = nt_atoi(line);
	bsq.lines = (unsigned char *)content + len;
	return (bsq);
}

t_bsq	bsq_valid_line(t_bsq bsq)
{
	int a;
	int line_size;

	a = 0;
	line_size = 0;
	while (bsq.lines[a])
	{
		if (bsq.lines[a] == '\n')
		{
			if (bsq.lines_size == -1)
				bsq.lines_size = line_size;
			else if (bsq.lines_size != line_size)
				return (bsq);
			line_size = 0;
		}
		else
		{
			if (bsq.lines[a] != bsq.empty && bsq.lines[a] != bsq.obstacle)
				return (bsq);
			line_size++;
		}
		a++;
	}
	bsq.valid = 1;
	return (bsq);
}

int		bsq_valid_lines(t_bsq bsq)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (bsq.lines[a])
	{
		if (bsq.lines[a] == '\n')
			count++;
		a++;
	}
	if (bsq.lines_count != count)
		return (0);
	return (1);
}

t_bsqr	bsqr_test(t_bsqr bsqr, int val, int x, int y)
{
	if (val > bsqr.max)
	{
		bsqr.max = val;
		bsqr.x = x;
		bsqr.y = y;
	}
	return (bsqr);
}

void	bsq_free(t_bsq bsq, char *content)
{
	int a;

	a = 0;
	if (bsq.lines_count < 255)
	{
		while (a < bsq.lines_count)
		{
			free(bsq.cval[a]);
			a++;
		}
		free(bsq.cval);
	}
	else
	{
		while (a < bsq.lines_count)
		{
			free(bsq.sval[a]);
			a++;
		}
		free(bsq.sval);
	}
	free(content);
}
