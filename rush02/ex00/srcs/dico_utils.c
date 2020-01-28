/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:32:10 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/21 14:37:50 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_divisor(int nb)
{
	if (nb < 10)
		return (1);
	else if (nb < 100)
		return (10);
	else if (nb < 1000)
		return (100);
	else if (nb < 1000000)
		return (1000);
	else if (nb < 1000000000)
		return (1000000);
	return (1000000000);
}

int		ft_transform_num(int num)
{
	int div;

	div = ft_divisor(num);
	return (num / div * div);
}

void	ft_write_dico(t_delem **dico, int id, int space)
{
	if (space)
		write(1, " ", 1);
	write(1, dico[id]->info, ft_strlen(dico[id]->info));
}

void	ft_generate_auto(t_delem **dico, int nb, int space, int done)
{
	int div;

	div = ft_divisor(nb);
	if (div < 100)
		nb = nb - div;
	else
		nb = nb / div;
	ft_generate_dico(dico, nb, space, done);
	if (!done)
		ft_generate_dico(dico, div, 1, 1);
}

char	ft_find_auto(t_delem **dico, int num, int space, int done)
{
	int i;

	if ((i = ft_find_dico(dico, num)) != -1)
	{
		if (!done && (num == 100 || num == 1000
		|| num == 1000000 || num == 1000000000))
		{
			ft_generate_dico(dico, num / ft_divisor(num), space, 1);
			space = 1;
		}
		ft_write_dico(dico, i, space);
		return (1);
	}
	return (0);
}
