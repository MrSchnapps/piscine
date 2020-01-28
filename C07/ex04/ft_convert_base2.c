/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:21:10 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/13 15:23:03 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_putnbr_base2(int nbr, char *base, char *nbr_convert, int memory)
{
	unsigned int	i_base;
	unsigned int	nb_p;

	i_base = 0;
	nb_p = nbr;
	if (nbr < 0)
	{
		nbr_convert[0] = '-';
		nb_p = nbr * -1;
	}
	while (base[i_base])
		i_base++;
	if (nb_p >= i_base)
		ft_putnbr_base2(nb_p / i_base, base, nbr_convert, memory - 1);
	nbr_convert[memory] = base[nb_p % i_base];
	return (nbr_convert);
}

void	ft_memory(int nbr, char *base, int *memory)
{
	unsigned int	i_base;
	unsigned int	nb_p;

	i_base = 0;
	nb_p = nbr;
	if (nbr < 0)
	{
		*memory += 1;
		nb_p = nbr * -1;
	}
	while (base[i_base])
		i_base++;
	if (nb_p >= i_base)
		ft_memory(nb_p / i_base, base, memory);
	*memory += 1;
}

int		ft_strstr_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || (base[i] >= 9 && base[i] <= 13)
				|| base[i] == ' ')
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

int		ft_check_bases(char *base_from, char *base_to)
{
	int i;

	i = 0;
	while (base_from[i] && base_to[i])
		i++;
	if (base_from[0] == '\0' || base_to[0] == '\0' || i == 1)
		return (0);
	if (!(ft_strstr_base(base_from)) || !(ft_strstr_base(base_to)))
		return (0);
	return (1);
}
