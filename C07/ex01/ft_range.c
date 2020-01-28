/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:19:04 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/09 15:37:26 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int cmpt;
	int *tab;

	if (min >= max)
		tab = NULL;
	else
	{
		cmpt = max - min;
		tab = malloc(cmpt * 4);
		i = 0;
		while (min < max)
		{
			tab[i] = min;
			min++;
			i++;
		}
	}
	return (tab);
}
