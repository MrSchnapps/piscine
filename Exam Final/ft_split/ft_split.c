/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:21:40 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:55:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_place_words(char **tab, char *str)
{
	int     i;
	int		j;
	int		i_tab;

	i = 0;
	j = 0;
	i_tab = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		j = 0;
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
		{	
			tab[i_tab][j] = str[i];
			i++;
			j++;
		}
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i]) 
			i++;
		tab[i_tab][j] = '\0';
		i_tab++;
	}
	tab[i_tab] = NULL;
	return (tab);	
}

char	**ft_words_memory(char **tab, char *str)
{
	int     m_words;
	int     i;
	int		i_tab;

	i = 0;
	i_tab = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		m_words = 0;
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
		{
			i++;
			m_words++;
		}
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
			i++;
		if (!(tab[i_tab] = malloc((m_words + 1) * sizeof(char))))
			return (NULL);
		i_tab++;
	}
	return (ft_place_words(tab, str));
}

char	**ft_all_memory(char *str)
{
	int		m;
	int		i;
	char	**tab;

	m = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
			i++;
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
			i++;
		m++;
	}
	if (!(tab = malloc((m + 1) * sizeof(char *))))
		return (NULL);
	return (ft_words_memory(tab, str));
}

char    **ft_split(char *str)
{	
	char **tab;

	tab = ft_all_memory(str);
	return (tab);
}
