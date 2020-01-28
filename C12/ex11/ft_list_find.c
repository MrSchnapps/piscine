/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:28:32 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 14:01:13 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *route;

	route = begin_list;
	if (!begin_list)
		return (NULL);
	while (route)
	{
		if ((*cmp)(route->data, data_ref) == 0)
			return (route);
		route = route->next;
	}
	return (NULL);
}
