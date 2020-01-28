/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:00:00 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 23:47:38 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	int		i;
	t_list	*parcours;

	i = 0;
	parcours = begin_list;
	if (!(begin_list))
		return (NULL);
	while (parcours)
	{
		if (!(parcours->next))
			return (parcours);
		parcours = parcours->next;
	}
	return (parcours);
}
