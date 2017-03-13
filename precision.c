/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:07:51 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:31:06 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include <stdarg.h>
#include <stdlib.h>

void	check_precision(const char *fmt, va_list args, size_t *i, int *precision)
{
	if (fmt[*i] != '.')
	{
		*precision = -1;
		return ;
	}
	(*i)++;
	if (fmt[*i] != '*')
	{
		*precision = string_to_number(fmt + *i);
		while (char_is_digit(fmt[*i]))
			(*i)++;
	}
	else
	{
		*precision = va_arg(args, int);
		if (*precision < 0)
			*precision = -1;
		(*i)++;
	}
}
