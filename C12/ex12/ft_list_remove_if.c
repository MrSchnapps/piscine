/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 00:09:22 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 00:09:25 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*route;
	t_list	*temp;

	route = *begin_list;
	temp = 0;
	if (!(begin_list))
		return ;
	while (route)
	{
		if (!(*cmp)(route->data, data_ref))
		{
			if (!temp)
				*begin_list = route->next;
			else
				temp->next = route->next;
			free_fct(route->data);
			free(route);
			route = temp;
		}
		else
		{
			temp = route;
			route = route->next;
		}
	}
}
