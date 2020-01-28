/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbucquoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:49:12 by vbucquoy          #+#    #+#             */
/*   Updated: 2019/07/07 13:28:45 by vbucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int x, char a, char b)
{
	int i;

	i = 1;
	ft_putchar(a);
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
			ft_print_line(x, 'A', 'B');
		else if (i == y)
			ft_print_line(x, 'C', 'B');
		else
			ft_print_line(x, 'B', ' ');
		i++;
	}
}
