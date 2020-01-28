/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:24:22 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/03 11:05:08 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar2(int nb)
{
	ft_putchar(nb / 10 + '0');
	ft_putchar(nb % 10 + '0');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 00;
	b = 01;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_putchar2(a);
			ft_putchar(' ');
			ft_putchar2(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			if (b == 99)
			{
				a++;
				b = a;
			}
			b++;
		}
	}
}
