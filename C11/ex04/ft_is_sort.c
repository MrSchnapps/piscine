/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:41:39 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/18 10:49:34 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sort_inc(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_sort_dec(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_sort_inc(tab, length, f)
				|| ft_sort_dec(tab, length, f))
		return (1);
	return (0);
}
