/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbucquoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:43:35 by vbucquoy          #+#    #+#             */
/*   Updated: 2019/07/07 13:30:27 by vbucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int x, char a, char b)
{
	int i;

	i = 1;
	while (i < x - 1)
	{
		ft_putchar(b);
		i++;
	}
	if (x > 1)
	{
		ft_putchar(a);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	while (i <= y && x > 0)
	{
		if (i == 1)
		{
			ft_putchar('A');
			ft_print_line(x, 'C', 'B');
		}
		else if (i == y)
		{
			ft_putchar('A');
			ft_print_line(x, 'C', 'B');
		}
		else
		{
			ft_putchar('B');
			ft_print_line(x, 'B', ' ');
		}
		i++;
	}
}
