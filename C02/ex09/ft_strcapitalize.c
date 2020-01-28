/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:51:58 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/04 14:26:16 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (!(str[i - 1] >= 97 && str[i - 1] <= 122) &&
					!(str[i - 1] >= 65 && str[i - 1] <= 90) &&
					!(str[i - 1] >= 48 && str[i - 1] <= 57))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
