/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:42:59 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 11:00:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_arg2(char *str, char c)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_arg1(char *str, char c, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (ft_check_arg1(argv[1], argv[1][i], i) && ft_check_arg2(argv[2], argv[1][i]))
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
