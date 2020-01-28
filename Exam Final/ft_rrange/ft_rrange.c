/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:12:26 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:01:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int i;
	int *tab;
	int size;

	i = 0;
	if (start < end)
	{
		size = (end - start) + 1;
		if (!(tab = (int *)malloc(size * sizeof(int))))
			return (NULL);
		while (end >= start)
		{
			tab[i] = end;
			if (end == -2147483648)
				break ;
			end--;
			i++;
		}
	}
	else
	{
		size = start - end + 1;
		if (!(tab = (int *)malloc(size * sizeof(int))))
			return (NULL);
		while (end <= start)
		{
			tab[i] = end;
			if (end == 2147483647)
				break ;
			end++;
			i++;
		}
	}
	return (tab);
}
