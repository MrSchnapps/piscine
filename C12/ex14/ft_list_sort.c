/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:29:58 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 15:46:55 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sort_list(t_list **start, t_list *temp, int (*cmp)())
{
	t_list	*element;

	element = *start;
	while (cmp(temp->data, element->data) < 0)
	{
		temp->next = element;
		*start = temp;
		return ;
	}
	while (element)
	{
		if (!element->next || cmp(temp->data, element->next->data) < 0)
		{
			temp->next = element->next;
			element->next = temp;
			return ;
		}
		element = element->next;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *start;
	t_list *temp;
	t_list *route;

	if (!(*begin_list))
		return ;
	start = *begin_list;
	temp = start->next;
	start->next = NULL;
	while (temp)
	{
		route = temp->next;
		ft_sort_list(&start, temp, cmp);
		temp = route;
	}
	*begin_list = start;
}
