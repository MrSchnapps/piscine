/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:12:15 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/13 15:13:53 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] < 10 - size)
		write(1, ", ", 2);
}

void	ft_print_un(void)
{
	int i;

	i = -1;
	while (++i < 10)
	{
		ft_putchar(i + '0');
		if (i != 9)
			write(1, ", ", 2);
	}
	ft_putchar('\n');
}

void	ft_print_combn(void)
{
	int i;

	i = 0;
}
