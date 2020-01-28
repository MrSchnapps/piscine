/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:31:16 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/23 14:11:14 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*route;

	if (!(begin_list))
		return ;
	route = begin_list;
	while (route)
	{
		(*f)(route->data);
		route = route->next;
	}
}
