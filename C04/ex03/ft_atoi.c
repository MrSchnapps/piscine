/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:33:13 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/07 10:13:36 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int signe;
	int cmpt;

	i = 0;
	signe = 1;
	cmpt = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cmpt += 1;
		i++;
	}
	if (cmpt % 2 == 1)
		signe = -1;
	cmpt = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		cmpt = (cmpt * 10) + str[i] - '0';
		i++;
	}
	cmpt *= signe;
	return (cmpt);
}
