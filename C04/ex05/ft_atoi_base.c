/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 23:55:59 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/07 09:59:58 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
		i++;
	if (base[0] == '\0' || i == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 33 || base[i] == 127)
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_i_number(char str, char *base)
{
	int i;

	i = 0;
	while (base[i] != str)
		i++;
	return (i);
}

int		ft_check_base(int i, char *str, char *base)
{
	int j;

	j = 0;
	while (base[j])
	{
		if (base[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

int		ft_convert_number(int i, char *str, char *base)
{
	int nbr;
	int i_base;

	nbr = 0;
	i_base = 0;
	while (base[i_base])
		i_base++;
	while (ft_check_base(i, str, base))
	{
		nbr = (nbr * i_base) + ft_i_number(str[i], base);
		i++;
	}
	return (nbr);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int signe;
	int nbr;

	if (ft_is_valid(base))
	{
		i = 0;
		signe = 1;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				signe *= -1;
			i++;
		}
		nbr = ft_convert_number(i, str, base);
		nbr *= signe;
		return (nbr);
	}
	return (0);
}
