/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:30:14 by lde-moul          #+#    #+#             */
/*   Updated: 2017/02/08 17:07:42 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include <inttypes.h>
#include <unistd.h>

static void	print_sign(intmax_t n, t_format *info)
{
	if (n < 0)
		info->written += write(1, "-", 1);
	else if (info->flags & PLUS_SIGN)
		info->written += write(1, "+", 1);
	else if (info->flags & BLANK_SIGN)
		info->written += write(1, " ", 1);
}

static void	init(intmax_t n, t_format *info, intmax_t *m, int *l)
{
	if (n >= 0)
	{
		*m = 1;
		*l = n || info->precision;
		if (info->flags & FORCE_SIGN)
			(*l)++;
		while (*m <= n / 10)
		{
			*m *= 10;
			(*l)++;
		}
	}
	else
	{
		*m = -1;
		*l = 2;
		while (*m >= n / 10)
		{
			*m *= 10;
			(*l)++;
		}
	}
}

void		print_signed(intmax_t n, t_format *info)
{
	intmax_t	m;
	int			l;
	int			sign;
	char		s[40];
	int			i;

	init(n, info, &m, &l);
	sign = n < 0 || info->flags & FORCE_SIGN;
	info->length = info->precision != -1 && info->precision + sign > l ?
		info->precision + sign : l;
	pad_left(info);
	if (n || info->precision != 0)
	{
		print_sign(n, info);
		pad_zero(l, sign, info);
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
