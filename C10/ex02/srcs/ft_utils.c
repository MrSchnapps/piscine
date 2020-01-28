/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:59:57 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/18 22:39:17 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_print_name(int argc, int i, int choice, char *avi)
{
	if (choice == 1)
	{
		if (argc > 4 && i > 3)
			write(1, "\n", 1);
	}
	if (choice == 2)
	{
		write(1, "==> ", 4);
		ft_putstr(avi, 1);
		write(1, " <==\n", 5);
	}
}

void	ft_print_tail(char *str, unsigned int cmpt_memory, unsigned int size)
{
	unsigned int	i_offset;

	i_offset = (cmpt_memory - size);
	if (size > cmpt_memory)
		i_offset = 0;
	while (i_offset < cmpt_memory)
	{
		ft_putchar(str[i_offset]);
		i_offset++;
	}
}
