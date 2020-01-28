/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:49:27 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 23:35:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap_list(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int		ft_size_list(t_list *begin_list)
{
	int		i;
	t_list	*route;

	i = 0;
	route = begin_list;
	while (route)
	{
		route = route->next;
		i++;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*route;
	int		i;
	int		j;

	i = ft_size_list(begin_list);
	if (begin_list)
	{
		while (i > 0)
		{
			j = i - 1;
			route = begin_list;
			while (route->next && j > 0)
			{
				ft_swap_list(route, route->next);
				route = route->next;
				j--;
			}
			i--;
		}
	}
}
