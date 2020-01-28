/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:59:05 by mbochet           #+#    #+#             */
/*   Updated: 2019/07/24 18:54:06 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	nt_is_space(char c)
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

int		nt_atoi(char *str)
{
	unsigned int	res;

	res = 0;
	while (nt_is_space(*str))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int		nt_strlen(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int		nt_min(int a, int b, int c)
{
	int min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int		nt_val(t_bsq *bsq, char c)
{
	if (c == bsq->empty)
		return (1);
	return (0);
}
