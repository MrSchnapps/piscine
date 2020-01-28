/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:39:03 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/21 12:26:26 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*parcours;

	i = 0;
	parcours = begin_list;
	while (parcours)
	{
		parcours = parcours->next;
		i++;
	}
	return (i);
}
