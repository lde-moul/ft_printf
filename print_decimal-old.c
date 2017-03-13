/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:11:24 by lde-moul          #+#    #+#             */
/*   Updated: 2017/01/25 17:45:14 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include <unistd.h>

static void	print_sign(const int n, t_format *info)
{
	if (n < 0)
		info->written += write(1, "-", 1);
	else if (info->flags & PLUS_SIGN)
		info->written += write(1, "+", 1);
	else if (info->flags & BLANK_SIGN)
		info->written += write(1, " ", 1);
}

static void	init(int n, const t_format *info, int *m, int *l)
{
	if (n >= 0)
	{
		*m = 1;
		*l = info->flags & FORCE_SIGN ? 2 : 1;
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

void		print_decimal(int n, t_format *info)
{
	int		m;
	int		l;
	int		sign;
	char	s[10];
	int		i;

	init(n, info, &m, &l);
	sign = n < 0 || info->flags & FORCE_SIGN;
	info->length = info->precision + sign > l ? info->precision + sign : l;
	pad_left(info);
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
	pad_right(info);
}
