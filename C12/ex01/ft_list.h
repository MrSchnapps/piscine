/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 08:21:48 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/25 00:00:29 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIST_H
# define _FT_LIST_H

# include <stdlib.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

t_list			*ft_create_elem(void *data);
#endif
