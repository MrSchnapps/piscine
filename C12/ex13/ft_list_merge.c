/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 08:17:41 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 14:30:32 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*route;

	route = *begin_list1;
	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (route->next)
		route = route->next;
	route->next = begin_list2;
}
