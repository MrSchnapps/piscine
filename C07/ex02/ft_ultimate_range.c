/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:45:56 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/09 18:46:01 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int cmpt;
	int *tab;

	i = 0;
	if (min >= max)
	{
		return (0);
	}
	else
	{
		cmpt = max - min;
		tab = (int *)malloc(cmpt * sizeof(tab));
		while (min < max)
		{
			tab[i] = min;
			min++;
			i++;
		}
		*range = tab;
		return (cmpt);
	}
	return (0);
}
