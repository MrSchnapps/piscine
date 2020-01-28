/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:48:09 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/17 15:48:03 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *tab_out;
	int i;

	i = 0;
	if (!(tab_out = malloc(length * sizeof(int))))
		return (0);
	while (i < length)
	{
		tab_out[i] = (*f)(tab[i]);
		i++;
	}
	return (tab_out);
}
