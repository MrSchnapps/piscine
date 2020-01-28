/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:59:04 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/24 18:53:29 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	g_enter = 0;

int		main(int argc, char **argv)
{
	int a;

	if (argc == 1)
	{
		bsq(NULL);
		return (0);
	}
	a = 1;
	while (a < argc)
	{
		bsq(argv[a]);
		a++;
	}
	return (0);
}

void	bsq(char *filename)
{
	char	*content;
	t_bsq	bsq;

	if (g_enter)
		write(1, "\n", 1);
	if ((content = file_read_content(filename)))
	{
		bsq = bsq_read(content);
		if (bsq.valid)
		{
			g_enter = 1;
			if (bsq.lines_count < 255)
				bsq = bsq_resolv_char(bsq);
			else
				bsq = bsq_resolv_short(bsq);
			if (bsq.valid)
				write(1, bsq.lines, bsq.lines_count * (bsq.lines_size + 1));
			else
				write(2, "map error\n", 10);
			bsq_free(bsq, content);
			return ;
		}
	}
	write(2, "map error\n", 10);
}

t_bsq	bsq_read(char *content)
{
	static t_bsq	bsq;
	char			*line;

	bsq.valid = 0;
	if (!(line = str_nextline(content)))
		return (bsq);
	bsq = bsq_read_firstline(bsq, line, content);
	if (!*bsq.lines || !bsq.lines_count)
		return (bsq);
	bsq.lines++;
	bsq = bsq_valid_line(bsq);
	if (!bsq.valid)
		return (bsq);
	if (!bsq_valid_lines(bsq))
	{
		bsq.valid = 0;
		return (bsq);
	}
	bsq.valid = 1;
	free(line);
	return (bsq);
}
