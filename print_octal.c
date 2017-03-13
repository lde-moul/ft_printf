/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:09:25 by lde-moul          #+#    #+#             */
/*   Updated: 2017/02/09 15:51:25 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "padding.h"
#include "format.h"
#include <inttypes.h>
#include <unistd.h>

static void	init(uintmax_t n, t_format *info, uintmax_t *m, int *l)
{
	*m = 1;
	*l = n || info->precision;
	while (*m <= n / 8)
	{
		*m *= 8;
		(*l)++;
	}
	if (info->flags & ALTERNATE_FORM && info->precision <= *l)
	{
		if (n)
			info->precision = *l + 1;
		else
		{
			info->precision = 1;
			*l = 1;
		}
	}
	info->length = info->precision != -1 && info->precision > *l ?
		info->precision : *l;
}

void		print_octal(uintmax_t n, t_format *info)
{
	uintmax_t	m;
	int			l;
	int			i;
	char		s[43];

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
			m /= 8;
		}
		info->written += write(1, s, i);
	}
	pad_right(info);
}
