/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:58:43 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 14:19:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*route;
	t_list	*temp;

	route = *begin_list;
	temp = 0;
	if (!(*begin_list))
		return ;
	while (route)
	{

		if (!(cmp(route->data, data_ref)))
		{	
			if (!temp)
			{
				temp = route->next;
				free(route);
				route = temp;
				*begin_list = route;
			}
			else
			{
				temp->next = route->next;
				free(route);
				route = temp->next;
			}
		}
		else
		{
			temp = route;
			route = route->next;
		}
	}
}
