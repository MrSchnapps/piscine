/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_resolv_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:54 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 20:15:20 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	bsq_resolv_char(t_bsq bsq)
{
	bsq.valid = 0;
	bsq = bsq_char_to_val(bsq);
	if (!bsq.valid)
		return (bsq);
	bsq = bsq_resolv_algo_char(bsq);
	bsq = bsq_val_to_char(bsq, bsq.r.max, bsq.r.x, bsq.r.y);
	return (bsq);
}

t_bsq	bsq_char_to_val(t_bsq bsq)
{
	int a;
	int b;
	int id;

	a = 0;
	id = 1;
	if (!(bsq.cval = malloc(sizeof(char *) * bsq.lines_count)))
		return (bsq);
	while (a < bsq.lines_count)
	{
		b = 0;
		while (b < bsq.lines_size)
		{
			if (!b && !(bsq.cval[a] = malloc(sizeof(char) * bsq.lines_size)))
				return (bsq);
			if (bsq.lines[(a * (bsq.lines_size + 1)) + b] == bsq.empty)
				bsq.cval[a][b] = 1;
			else
				bsq.cval[a][b] = 0;
			b++;
		}
		a++;
	}
	bsq.valid = 1;
	return (bsq);
}

t_bsq	bsq_resolv_algo_char(t_bsq bsq)
{
	int a;
	int b;

	a = 0;
	bsq.r.max = -1;
	while (a < bsq.lines_count)
	{
		b = 0;
		while (b < bsq.lines_size)
		{
			if (a && b && bsq.cval[a][b] == 1)
				bsq.cval[a][b] = nt_min(bsq.cval[a][b - 1],
					bsq.cval[a - 1][b], bsq.cval[a - 1][b - 1]) + 1;
			bsq.r = bsqr_test(bsq.r, bsq.cval[a][b], a, b);
			b++;
		}
		a++;
	}
	return (bsq);
}

t_bsq	bsq_val_to_char(t_bsq bsq, int max, int x, int y)
{
	int a;
	int b;

	a = 0;
	while (a < bsq.lines_count)
	{
		b = 0;
		while (b < bsq.lines_size)
		{
			if ((a >= x - max + 1 && a <= x) && (b >= y - max + 1 && b <= y))
				bsq.lines[(a * (bsq.lines_size + 1)) + b] = bsq.full;
			else if (!bsq.cval[a][b])
				bsq.lines[(a * (bsq.lines_size + 1)) + b] = bsq.obstacle;
			else
				bsq.lines[(a * (bsq.lines_size + 1)) + b] = bsq.empty;
			b++;
		}
		a++;
	}
	return (bsq);
}
