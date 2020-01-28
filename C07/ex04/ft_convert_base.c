/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:29:49 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/13 15:22:44 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base2(int nbr, char *base, char *nbr_convert, int memory);

int		ft_memory(int nbr, char *base, int *memory);

int		ft_check_bases(char *base_from, char *base_to);

int		ft_i_number(char str, char *base)
{
	int i;

	i = 0;
	while (base[i] != str)
		i++;
	return (i);
}

int		ft_check_base(int i, char *str, char *base)
{
	int j;

	j = 0;
	while (base[j])
	{
		if (base[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

int		ft_convert_number(int i, int cmpt_sign, char *str, char *base)
{
	int nbr;
	int i_base;
	int signe;

	signe = 1;
	if (cmpt_sign % 2 == 1)
		signe = -1;
	nbr = 0;
	i_base = 0;
	while (base[i_base])
		i_base++;
	while (ft_check_base(i, str, base))
	{
		nbr = (nbr * i_base) + ft_i_number(str[i], base);
		i++;
	}
	nbr *= signe;
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		nbr_d;
	int		memory;
	char	*nbr_convert;
	int		cmpt_sign;

	cmpt_sign = 0;
	if (!(ft_check_bases(base_from, base_to)))
		return (0);
	memory = 0;
	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			cmpt_sign++;
		i++;
	}
	nbr_d = ft_convert_number(i, cmpt_sign, nbr, base_from);
	ft_memory(nbr_d, base_to, &memory);
	nbr_convert = malloc(memory + 1);
	nbr_convert = ft_putnbr_base2(nbr_d, base_to, nbr_convert, memory - 1);
	nbr_convert[memory] = 0;
	return (nbr_convert);
}
