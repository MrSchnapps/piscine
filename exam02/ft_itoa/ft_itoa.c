/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:12:11 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 18:51:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memory(unsigned int nb)
{
	int cmpt;

	cmpt = 0;
	while (nb > 0)
	{
		nb /= 10;
		cmpt++;
	}
	return (cmpt);	
}

char	*ft_putnbr_char(unsigned int nb, char *tab_nbr, int cmpt_memory)
{
	char	base[] = "0123456789";
	if (nb > 9)
		ft_putnbr_char(nb / 10, tab_nbr, cmpt_memory - 1);
	tab_nbr[cmpt_memory] = base[nb % 10];
	return (tab_nbr);	
}

char	*ft_itoa(int nbr)
{
	unsigned int 	nb;
	int				cmpt_memory;
	char			*tab_nbr;

	if (nbr == 0)
		return ("0");
	cmpt_memory = 0;
	nb = nbr;
	if (nbr < 0)
	{
		nb = nbr * -1;
		cmpt_memory += 1;
	}
	cmpt_memory += ft_memory(nb);
	if (!(tab_nbr = (char *)malloc((cmpt_memory + 1) * sizeof(char))))
		return (NULL);
	if (nbr < 0)
		tab_nbr[0] = '-';
	tab_nbr = ft_putnbr_char(nb, tab_nbr, cmpt_memory - 1);
	tab_nbr[cmpt_memory] = '\0';
	return (tab_nbr);
}
