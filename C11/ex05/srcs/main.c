/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:19:08 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/18 10:53:23 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdio.h>

int		ft_atoi2(char *str)
{
	int i;
	int cmpt_signe;
	int signe;
	int nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	cmpt_signe = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cmpt_signe++;
		i++;
	}
	if (cmpt_signe % 2)
		signe = -1;
	while (str[i] >= 48 && str[i] <= 57)
		nbr = (nbr * 10) + str[i++] - '0';
	nbr *= signe;
	return (nbr);
}

int		ft_verif(int nb2, char *op)
{
	if (ft_strlen(op) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (op[0] != 37 && op[0] != 42 && op[0] != 43 && op[0] != 45 && op[0] != 47)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (op[0] == '/' && nb2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op[0] == '%' && nb2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		nb1;
	int		nb2;
	int		(*ft_op[5])(int nb1, int nb2);
	char	*sign;

	ft_op[0] = ft_add;
	ft_op[1] = ft_sub;
	ft_op[2] = ft_div;
	ft_op[3] = ft_mul;
	ft_op[4] = ft_mod;
	sign = "+-/*%";
	if (argc != 4)
		return (0);
	nb1 = ft_atoi2(argv[1]);
	nb2 = ft_atoi2(argv[3]);
	if (!(ft_verif(nb2, argv[2])))
		return (0);
	i = 0;
	while (sign[i] != argv[2][0])
		i++;
	ft_putnbr((ft_op[i])(nb1, nb2));
	write(1, "\n", 1);
}
