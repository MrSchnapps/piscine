/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:26:39 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/05 16:06:37 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(int nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16);
	ft_putchar(tab[nb % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int nbr;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ft_putchar('\\');
			nbr = (unsigned char)str[i];
			if (nbr < 16)
				ft_putchar('0');
			ft_puthex(nbr);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
