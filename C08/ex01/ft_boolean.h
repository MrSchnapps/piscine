/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:09:27 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/11 22:29:20 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_BOOLEAN_H
# define _FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN(nbr) (nbr % 2 == 0) ? TRUE : FALSE

typedef int		t_bool;
#endif
