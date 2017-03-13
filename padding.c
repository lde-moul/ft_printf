/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:12:13 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 14:52:33 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <unistd.h>

static int	print_spaces(int n)
{
	int written;

	written = 0;
	while (n >= 40)
	{
		written += write(1, "                                        ", 40);
		n -= 40;
	}
	if (n > 0)
		written += write(1, "                                       ", n);
	return (written);
}

static int	print_zeros(int n)
{
	int written;

	written = 0;
	while (n >= 40)
	{
		written += write(1, "0000000000000000000000000000000000000000", 40);
		n -= 40;
	}
	if (n > 0)
		written += write(1, "000000000000000000000000000000000000000", n);
	return (written);
}

void		pad_left(t_format *info)
{
	if ((info->flags & ZERO_PADDING && info->precision == -1)
	|| info->flags & RIGHT_PADDING)
		info->written = 0;
	else
		info->written = print_spaces(info->width - info->length);
}

void		pad_right(t_format *info)
{
	if (info->flags & RIGHT_PADDING)
		info->written += print_spaces(info->width - info->length);
}

void		pad_zero(int l, int sign, t_format *info)
{
	if (info->precision != -1)
		info->written += print_zeros(info->precision - l + sign);
	else if (info->flags & ZERO_PADDING)
		info->written += print_zeros(info->width - l);
}
