/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:28:57 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/17 16:36:27 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_H
# define _FT_H
# include <unistd.h>

int		ft_add(int nb1, int nb2);
int		ft_sub(int nb1, int nb2);
int		ft_div(int nb1, int nb2);
int		ft_mul(int nb1, int nb2);
int		ft_mod(int nb1, int nb2);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
#endif
