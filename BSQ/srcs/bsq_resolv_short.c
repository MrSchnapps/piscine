/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_resolv_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:14:49 by judecuyp          #+#    #+#             */
/*   Updated: 2019/07/24 20:21:02 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	bsq_resolv_short(t_bsq bsq)
{
	bsq.valid = 0;
	bsq = bsq_short_to_val(bsq);
	if (!bsq.valid)
		return (bsq);
	bsq = bsq_resolv_algo_short(bsq);
	bsq = bsq_val_to_short(bsq, bsq.r.max, bsq.r.x, bsq.r.y);
	return (bsq);
}

t_bsq	bsq_short_to_val(t_bsq bsq)
{
	int a;
	int b;
	int id;

	a = 0;
	id = 1;
	if (!(bsq.sval = malloc(sizeof(int *) * bsq.lines_count)))
		return (bsq);
	while (a < bsq.lines_count)
	{
		b = 0;
		while (b < bsq.lines_size)
		{
			if (!b && !(bsq.sval[a] = malloc(sizeof(int) * bsq.lines_size)))
				return (bsq);
			if (bsq.lines[(a * (bsq.lines_size + 1)) + b] == bsq.empty)
				bsq.sval[a][b] = 1;
			else
				bsq.sval[a][b] = 0;
			b++;
		}
		a++;
	}
	bsq.valid = 1;
	return (bsq);
}

t_bsq	bsq_resolv_algo_short(t_bsq bsq)
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
			if (a && b && bsq.sval[a][b] == 1)
				bsq.sval[a][b] = nt_min(bsq.sval[a][b - 1],
					bsq.sval[a - 1][b], bsq.sval[a - 1][b - 1]) + 1;
			bsq.r = bsqr_test(bsq.r, bsq.sval[a][b], a, b);
			b++;
		}
		a++;
	}
	return (bsq);
}

t_bsq	bsq_val_to_short(t_bsq bsq, int max, int x, int y)
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
			else if (!bsq.sval[a][b])
				bsq.lines[(a * (bsq.lines_size + 1)) + b] = bsq.obstacle;
			else
				bsq.lines[(a * (bsq.lines_size + 1)) + b] = bsq.empty;
			b++;
		}
		a++;
	}
	return (bsq);
}
