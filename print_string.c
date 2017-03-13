/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:00:10 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 15:08:38 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include <unistd.h>

void	print_string(char *s, t_format *info)
{
	if (!s)
		s = "(null)";
	info->length = 0;
	if (info->precision == -1)
		while (s[info->length])
			info->length++;
	else
		while (s[info->length] && info->length < info->precision)
			info->length++;
	if (info->flags & ZERO_PADDING)
		info->precision = -1;
	pad_left(info);
	if (info->flags & ZERO_PADDING)
		pad_zero(info->length, 0, info);
	info->written += write(1, s, info->length);
	pad_right(info);
}
