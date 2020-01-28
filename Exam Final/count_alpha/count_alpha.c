/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:25:46 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 16:00:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_str_lowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
int		ft_check_in_base(char *str, char c, int tab[26])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (tab[i] == 0)
				return (i);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int     ft_check_is_printable(char *str, char c, int tab[26])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (tab[i] == 0)
				return (i);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
	return (1);
}

int     place_virgule(char *argv, char *str, int tab[26], int i)
{
	while (argv[i])
	{
		if (ft_check_in_base(str, argv[i], tab) != -1)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{	
	char	str[27] = "abcdefghijklmnopqrstuvwxyz";
	int		tab_i[26];
	int		i;
	int		j;
	int		cmpt;
	int		i_cmpt;
	char	*av;

	if (argc == 2)
	{	
		av = ft_str_lowcase(argv[1]);
		i = 0;
		while (i < 26)
		{
			tab_i[i] = 0;
			i++;
		}
		i = 0;
		while (av[i])
		{
			if ((i_cmpt = ft_check_in_base(str, av[i], tab_i)) != -1)
			{
				j = 0;
				cmpt = 0;
				while (av[j])
				{
					if (av[i] == av[j])
						cmpt++;
					j++;
				}
				tab_i[i_cmpt] = cmpt;
				printf("%d%c", tab_i[i_cmpt], av[i]);
				if (!(place_virgule(av, str, tab_i, i + 1)))
					printf(", ");
			}
			i++;	
		}
	}
	printf("\n");
	return (0);
}
