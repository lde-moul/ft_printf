/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:49:19 by lde-moul          #+#    #+#             */
/*   Updated: 2017/02/09 15:57:38 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include "conversion.h"
#include <inttypes.h>
#include <unistd.h>

static void	init(uintmax_t n, t_format *info, uintmax_t *m, int *l)
{
	*m = 1;
	*l = n || info->precision;
	while (*m <= n / 16)
	{
		*m *= 16;
		(*l)++;
	}
	if (info->precision != -1 && info->precision > *l)
		info->length = info->precision;
	else
		info->length = *l;
	if (info->flags & ALTERNATE_FORM && n)
		info->length += 2;
}

static void	print_0x(uintmax_t n, t_format *info)
{
	if (!(info->flags & ALTERNATE_FORM && n))
		return ;
	if (info->conversion_format == CONV_HEXADECIMAL)
		info->written += write(1, "0x", 2);
	else
		info->written += write(1, "0X", 2);
}

static int	zero_padding(t_format *info)
{
	return (info->flags & ALTERNATE_FORM && info->flags & ZERO_PADDING);
}

void		print_hexadecimal(uintmax_t n, t_format *info)
{
	uintmax_t	m;
	int			l;
	int			i;
	char		s[32];
	char		letter;

	init(n, info, &m, &l);
	pad_left(info);
	print_0x(n, info);
	if (n || info->precision != 0)
	{
		pad_zero(zero_padding(info) && n ? l + 2 : l, 0, info);
		letter = info->conversion_format == CONV_HEXADECIMAL ? 'a' : 'A';
		i = 0;
		while (m)
		{
			s[i++] = (n / m < 10) ? (n / m + '0') : (n / m - 10 + letter);
			n %= m;
			m /= 16;
		}
		info->written += write(1, s, i);
	}
	pad_right(info);
}
