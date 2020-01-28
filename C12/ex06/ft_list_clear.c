/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:35:44 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 23:54:31 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdio.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;
	t_list	*route;

	route = begin_list;
	if (!(begin_list))
		return ;
	while (route)
	{
		temp = route->next;
		free_fct(route->data);
		free(route);
		route = temp;
	}
}
