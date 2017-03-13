/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:08:03 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 17:52:59 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include "format.h"
#include <stdarg.h>
#include <stdlib.h>

static void	check_dynamic_width(va_list args, size_t *i, t_format *inf)
{
	inf->width = va_arg(args, int);
	if (inf->width < 0)
	{
		inf->flags |= RIGHT_PADDING;
		inf->width = -inf->width;
	}
	(*i)++;
}

void		check_width(const char *fmt, va_list args, size_t *i, t_format *inf)
{
	if (fmt[*i] != '*')
	{
		inf->width = string_to_number(fmt + *i);
		while (char_is_digit(fmt[*i]))
			(*i)++;
		if (fmt[*i] == '*')
			check_dynamic_width(args, i, inf);
	}
	else
	{
		check_dynamic_width(args, i, inf);
		if (char_is_digit(fmt[*i]))
		{
			inf->width = string_to_number(fmt + *i);
			while (char_is_digit(fmt[*i]))
				(*i)++;
		}
	}
}
