/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:23:44 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 23:51:47 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list	*route;
	t_list	*start;

	if (size == 0)
		return (0);
	size--;
	start = ft_create_elem(strs[size--]);
	route = start;
	if (start)
	{
		while (size >= 0)
		{
			route->next = ft_create_elem(strs[size--]);
			route = route->next;
		}
	}
	return (start);
}
