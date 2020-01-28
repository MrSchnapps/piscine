/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:27:41 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/17 15:42:21 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		size;
	int		booleen;
	char	*temp;

	size = 0;
	while (tab[size])
		size++;
	booleen = 1;
	while (booleen)
	{
		i = 0;
		booleen = 0;
		while (i < size - 1)
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				booleen = 1;
			}
			i++;
		}
	}
}
