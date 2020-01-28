/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:03:51 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/07 10:06:18 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
		i++;
	if (base[0] == '\0' || i == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 33 || base[i] == 127)
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i_base;
	unsigned int	nb_p;

	if (ft_check(base))
	{
		i_base = 0;
		nb_p = nbr;
		if (nbr < 0)
		{
			ft_putchar('-');
			nb_p = nbr * -1;
		}
		while (base[i_base])
			i_base++;
		if (nb_p >= i_base)
			ft_putnbr_base(nb_p / i_base, base);
		ft_putchar(base[nb_p % i_base]);
	}
}
