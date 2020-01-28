/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:00:00 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/07 18:40:36 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_absolute(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int		ft_check_queens(int row, int tab[10])
{
	int col;

	col = 0;
	while ((tab[row] != tab[col]) &&
			(ft_absolute(tab[row] - tab[col]) != row - col)
			&& (col < 10))
		col++;
	if (col == row)
		return (1);
	return (0);
}

void	ft_backtracking(int tab[10], int row, int *count)
{
	int cmpt;

	tab[row] = 0;
	while (tab[row] < 10)
	{
		if (ft_check_queens(row, tab))
		{
			if (row == 9)
			{
				cmpt = 0;
				while (cmpt < 10)
				{
					ft_putchar(tab[cmpt] + '0');
					cmpt++;
				}
				ft_putchar('\n');
				*count += 1;
			}
			else
				ft_backtracking(tab, row + 1, count);
		}
		tab[row]++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int count;
	int tab_pos[10];
	int i;

	count = 0;
	i = 0;
	while (tab_pos[i])
		tab_pos[i] = -1;
	ft_backtracking(tab_pos, 0, &count);
	return (count);
}
