/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:08:03 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 17:19:07 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include "format.h"
#include <stdarg.h>
#include <stdlib.h>

static void check_dynamic_width(va_list args, size_t *i, t_format *info)
{
	info->width = va_arg(args, int);
	if (info->width < 0)
	{
		info->flags |= RIGHT_PADDING;
		info->width = -info->width;
	}
	(*i)++;
}

void		check_width(const char *fmt, va_list args, size_t *i, t_format *info)
{
	if (fmt[*i] != '*')
	{
		info->width = string_to_number(fmt + *i);
		while (char_is_digit(fmt[*i]))
			(*i)++;
		if (fmt[*i] == '*')
			check_dynamic_width(args, i, info);
	}
	else
	{
		check_dynamic_width(args, i, info);
		if (char_is_digit(fmt[*i]))
		{
			info->width = string_to_number(fmt + *i);
			while (char_is_digit(fmt[*i]))
				(*i)++;
		}
	}
}
