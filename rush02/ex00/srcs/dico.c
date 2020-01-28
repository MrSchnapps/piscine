/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:29:24 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/21 14:07:53 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_delem		**ft_read_dico(char *filename)
{
	t_delem		**dico;
	char		*content;
	char		*line;
	int			size;
	int			linecount;

	if (!(content = ft_file_content(filename)))
		return (NULL);
	if (!(dico = malloc(sizeof(t_delem *) * (ft_count_line(content) + 1))))
		return (NULL);
	size = 0;
	linecount = 0;
	while ((line = ft_next_line(content + size)))
	{
		if (!(dico[linecount] = ft_analyse_line(line)))
			return (NULL);
		size += ft_strlen(line) + 1;
		linecount++;
		free(line);
	}
	dico[linecount] = NULL;
	free(content);
	return (dico);
}

void		ft_swap_dico(t_delem *elem1, t_delem *elem2)
{
	int		num;
	char	*info;

	num = elem1->num;
	info = elem1->info;
	elem1->num = elem2->num;
	elem1->info = elem2->info;
	elem2->num = num;
	elem2->info = info;
}

void		ft_sort_dico(t_delem **dico)
{
	int a;

	a = 0;
	while (dico[a + 1] != NULL)
	{
		if (dico[a]->num > dico[a + 1]->num)
		{
			ft_swap_dico(dico[a], dico[a + 1]);
			a = 0;
		}
		a++;
	}
}

int			ft_find_dico(t_delem **dico, int num)
{
	int a;

	a = 0;
	while (dico[a] != NULL)
	{
		if (dico[a]->num == num)
			return (a);
		a++;
	}
	return (-1);
}

void		ft_generate_dico(t_delem **dico, int num, int space, int done)
{
	int nb;
	int div;
	int i;

	if (!num)
		return ;
	div = 1;
	if ((num > 100 && num <= 199) || (num > 1000 && num <= 1999)
	|| (num > 1000000 && num <= 1999999) ||
	(num > 1000000000 && num <= 1999999999))
	{
		write(1, "one", 3);
		space = 1;
	}
	nb = ft_transform_num(num);
	if (ft_find_auto(dico, num, space, done))
		return ;
	if ((i = ft_find_dico(dico, nb)) != -1)
		ft_write_dico(dico, i, space);
	else
		ft_generate_auto(dico, nb, space, done);
	ft_generate_dico(dico, num - (nb * div), 1, done);
}
