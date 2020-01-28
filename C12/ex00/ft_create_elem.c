/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:44:22 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 23:36:15 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list		*ft_create_elem(void *data)
{
	t_list	*new_struct;

	if (!(new_struct = malloc(sizeof(t_list))))
		return (NULL);
	new_struct->data = data;
	new_struct->next = NULL;
	return (new_struct);
}
