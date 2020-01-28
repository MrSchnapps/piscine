/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:33:31 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/13 12:31:05 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int cmpt;

	i = 0;
	j = 0;
	cmpt = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
		j++;
	cmpt = i + j;
	if (i == size)
		return (cmpt);
	j = 0;
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (cmpt);
}
