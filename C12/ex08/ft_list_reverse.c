/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:17:19 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 09:25:12 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prec;
	t_list	*suiv;
	t_list	*actu;

	prec = 0;
	suiv = 0;
	actu = *begin_list;
	if (!(begin_list))
		return ;
	while (actu)
	{
		suiv = actu->next;
		actu->next = prec;
		prec = actu;
		actu = suiv;
	}
	*begin_list = prec;
}
