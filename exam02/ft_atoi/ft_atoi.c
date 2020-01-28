/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:53:01 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 18:07:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' 
				|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	nbr *= signe;
	return (nbr);
}
