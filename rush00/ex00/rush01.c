/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbucquoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:33:22 by vbucquoy          #+#    #+#             */
/*   Updated: 2019/07/07 13:25:21 by vbucquoy         ###   ########.fr       */
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
			ft_putchar('/');
			ft_print_line(x, '\\', '*');
		}
		else if (i == y)
		{
			ft_putchar('\\');
			ft_print_line(x, '/', '*');
		}
		else
		{
			ft_putchar('*');
			ft_print_line(x, '*', ' ');
		}
		i++;
	}
}
