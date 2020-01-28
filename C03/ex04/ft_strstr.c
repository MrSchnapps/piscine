/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 00:33:34 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/06 16:03:45 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int nbr;

	i = 0;
	nbr = 0;
	while (to_find[nbr])
		nbr++;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
			j++;
		if (j == nbr)
			return (&str[i]);
		i++;
	}
	return (0);
}
