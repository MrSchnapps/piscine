/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:56:05 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/14 19:14:48 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_char(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_place_words(char **tab, char *str, int m, char *charset)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (ft_check_char(str[i], charset))
		i++;
	while (str[i])
	{
		k = 0;
		while (!(ft_check_char(str[i], charset)) && str[i])
			tab[j][k++] = str[i++];
		if (j < m)
		{
			tab[j][k] = 0;
			j++;
		}
		while (ft_check_char(str[i], charset))
			i++;
	}
	tab[m] = 0;
	return (tab);
}

char	**ft_m_l(char **tab, char *str, int m, char *charset)
{
	int i;
	int j;
	int m2;

	i = 0;
	j = 0;
	while (ft_check_char(str[i], charset))
		i++;
	while (str[i])
	{
		m2 = 0;
		while (!(ft_check_char(str[i], charset)) && str[i])
		{
			i++;
			m2++;
		}
		if (j < m)
		{
			tab[j] = malloc((m2 + 1) * sizeof(char));
			j++;
		}
		while (ft_check_char(str[i], charset))
			i++;
	}
	return (ft_place_words(tab, str, m, charset));
}

char	**ft_memory(char *str, char *charset)
{
	int		i;
	int		m;
	char	**tab;

	i = 0;
	m = 0;
	while (ft_check_char(str[i], charset))
		i++;
	while (str[i])
	{
		while (!(ft_check_char(str[i], charset)) && str[i])
			i++;
		while (ft_check_char(str[i], charset))
			i++;
		m++;
	}
	return (ft_m_l(tab = malloc((m + 1) * sizeof(char *)), str, m, charset));
}

char	**ft_split(char *str, char *charset)
{
	char **tab;

	tab = ft_memory(str, charset);
	return (tab);
}
