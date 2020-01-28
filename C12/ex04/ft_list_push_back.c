/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:36:17 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 09:35:25 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *elem;
	t_list *suivant;

	suivant = *begin_list;
	if (!(*begin_list))
	{
		elem = ft_create_elem(data);
		*begin_list = elem;
		return ;
	}
	elem = ft_create_elem(data);
	if (elem)
	{
		while (suivant->next)
			suivant = suivant->next;
		suivant->next = elem;
	}
}
