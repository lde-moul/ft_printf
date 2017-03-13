/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:11:24 by lde-moul          #+#    #+#             */
/*   Updated: 2017/02/09 15:52:34 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include <inttypes.h>
#include <unistd.h>

static void	init(uintmax_t n, t_format *info, uintmax_t *m, int *l)
{
	*m = 1;
	*l = n || info->precision;
	while (*m <= n / 10)
	{
		*m *= 10;
		(*l)++;
	}
	info->length = info->precision != -1 && info->precision > *l ?
		info->precision : *l;
}

void		print_decimal(uintmax_t n, t_format *info)
{
	uintmax_t	m;
	int			l;
	int			i;
	char		s[40];

	init(n, info, &m, &l);
	pad_left(info);
	if (n || info->precision != 0)
	{
		pad_zero(l, 0, info);
		i = 0;
		while (m)
		{
			s[i++] = n / m + '0';
			n %= m;
			m /= 10;
		}
		info->written += write(1, s, i);
	}
	pad_right(info);
}
