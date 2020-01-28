/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:30:47 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 17:50:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 1;
		if (i > 0)
		{
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			if (i > 0)
			{
				while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			 		i--;
				i += 1;
				while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				{
					ft_putchar(argv[1][i]);
					i++;
				}
			}
		}
	}
	ft_putchar('\n');
	return (0);	
}
