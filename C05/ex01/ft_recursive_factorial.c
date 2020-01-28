/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:55:42 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/08 17:08:38 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_factorial(int nb)
{
	int nbr;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	nbr = nb;
	return (nbr * ft_recursive_factorial(nb - 1));
}
