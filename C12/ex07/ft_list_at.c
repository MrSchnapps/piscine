/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:06:40 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 13:47:18 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*route;

	i = 0;
	if (!begin_list)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	else
	{
		route = begin_list;
		while (i < nbr)
		{
			if (route->next == NULL)
				return (NULL);
			route = route->next;
			i++;
		}
		return (route);
	}
}
