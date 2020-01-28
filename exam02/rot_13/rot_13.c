/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:13:03 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 17:27:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		while(argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'm')
					|| (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
				ft_putchar(argv[1][i] + 13);	
			else if ((argv[1][i] > 'm' && argv[1][i] <= 'z')
					|| (argv[1][i] > 'M' && argv[1][i] <= 'Z'))
				ft_putchar(argv[1][i] - 13);
			else
				ft_putchar(argv[1][i]);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
