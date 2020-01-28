/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:16:17 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/14 16:25:09 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	if (!(str = malloc((i + 1) * sizeof(*str))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = -1;
	if (!(tab = malloc((ac + 1) * sizeof(*tab))))
		return (NULL);
	while (++i < ac)
	{
		tab[i].str = av[i];
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(tab[i].str);
	}
	tab[ac].str = 0;
	tab[ac].size = 0;
	tab[ac].copy = 0;
	return (tab);
}
