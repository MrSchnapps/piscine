/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:29:24 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/21 14:20:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_freeall(t_delem **dico)
{
	int	a;

	a = 0;
	while (dico[a] != NULL)
	{
		free(dico[a]->info);
		free(dico[a]);
		a++;
	}
	free(dico);
}

char	ft_is_execep(int num)
{
	if (num == 100 ||
		num == 1000 ||
		num == 1000000 ||
		num == 1000000000)
		return (1);
	return (0);
}

int		main_dico(int num, char *filename)
{
	int		i;
	t_delem	**dico;

	if (!(dico = ft_read_dico(filename)))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	ft_sort_dico(dico);
	if (!ft_is_execep(num) && (i = ft_find_dico(dico, num)) != -1)
		write(1, dico[i]->info, ft_strlen(dico[i]->info));
	else
		ft_generate_dico(dico, num, 0, 0);
	ft_freeall(dico);
	write(1, "\n", 1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		num;
	char	*filename;

	filename = "numbers.dict";
	if (argc == 2)
		num = ft_atoi(argv[1]);
	else if (argc == 3)
	{
		filename = argv[1];
		num = ft_atoi(argv[2]);
	}
	else
		return (1);
	if (num < 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (main_dico(num, filename));
}
