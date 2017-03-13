/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:58:28 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 14:16:32 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "padding.h"
#include "format.h"
#include "conversion.h"
#include <unistd.h>

static void	init(size_t p, t_format *info, size_t *m, int *l)
{
	*m = 1;
	*l = p || info->precision;
	while (*m <= p / 16)
	{
		*m *= 16;
		(*l)++;
	}
	if (info->precision != -1 && info->precision > *l)
		info->length = info->precision + 2;
	else
		info->length = *l + 2;
}

void		print_pointer(size_t p, t_format *info)
{
	size_t	m;
	int		l;
	int		i;
	char	s[16];

	init(p, info, &m, &l);
	pad_left(info);
	info->written += write(1, "0x", 2);
	if (p || info->precision != 0)
	{
		pad_zero(info->flags & ZERO_PADDING ? l + 2 : l, 0, info);
		i = 0;
		while (m)
		{
			s[i++] = (p / m < 10) ? (p / m + '0') : (p / m - 10 + 'a');
			p %= m;
			m /= 16;
		}
		info->written += write(1, s, i);
	}
	pad_right(info);
}
