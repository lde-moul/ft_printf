/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:07:51 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 18:06:14 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "number.h"
#include <stdarg.h>
#include <stdlib.h>

void	check_precision(const char *fmt, va_list args, size_t *i, int *prec)
{
	if (fmt[*i] != '.')
	{
		*prec = -1;
		return ;
	}
	(*i)++;
	if (fmt[*i] != '*')
	{
		*prec = string_to_number(fmt + *i);
		while (char_is_digit(fmt[*i]))
			(*i)++;
	}
	else
	{
		*prec = va_arg(args, int);
		if (*prec < 0)
			*prec = -1;
		(*i)++;
	}
}
