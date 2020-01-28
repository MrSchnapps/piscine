/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:32:10 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/21 14:37:50 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_is_space(char c)
{
	if (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ')
		return (1);
	return (0);
}

char	ft_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int		ft_atoi(char *str)
{
	unsigned int	res;

	res = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	if (*str < '0' || *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str)
		return (-1);
	return (res);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (src[i])
	{
		if (!ft_is_printable(src[i]))
			return (NULL);
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (src[i])
	{
		if (!(i && src[i] == ' ' && src[i - 1] == ' '))
		{
			str[j] = src[i];
			j++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
