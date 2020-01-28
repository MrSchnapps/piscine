/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:34:03 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/23 23:26:36 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
		*data_ref, int (*cmp)())
{
	t_list *route;

	route = begin_list;
	if (!(begin_list))
		return ;
	while (route)
	{
		if ((*cmp)(route->data, data_ref) == 0)
			(*f)(route->data);
		route = route->next;
	}
}
