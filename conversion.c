/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:15:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 17:49:42 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static void	check_length(const char *fmt, size_t *i, char *length)
{
	*length = CONV_NONE;
	if (fmt[*i] == 'h')
	{
		*length = CONV_HH;
		if (fmt[*i + 1] == 'h')
			(*i)++;
		else
			*length = CONV_H;
	}
	else if (fmt[*i] == 'l')
	{
		*length = CONV_LL;
		if (fmt[*i + 1] == 'l')
			(*i)++;
		else
			*length = CONV_L;
	}
	else if (fmt[*i] == 'j')
		*length = CONV_J;
	else if (fmt[*i] == 'z')
		*length = CONV_Z;
	else
		return ;
	(*i)++;
}

static void	check_format(char c, char *format)
{
	if (c == 'x')
		*format = CONV_HEXADECIMAL;
	else if (c == 'X')
		*format = CONV_HEXADECIMAL_UPPER;
	else if (c == 'o' || c == 'O')
		*format = CONV_OCTAL;
	else
		*format = CONV_NONE;
}

static void	init(const char *fmt, size_t *i, t_format *info, char *c)
{
	info->conversion_type = CONV_NONE;
	info->written = 0;
	check_length(fmt, i, &info->conversion_length);
	*c = fmt[*i];
	check_format(*c, &info->conversion_format);
}

void		check_conversion(const char *fmt, size_t *i, t_format *info)
{
	char c;

	init(fmt, i, info, &c);
	if (c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'o' || c == 'O')
		info->conversion_type = CONV_UNSIGNED;
	else if (c == 'd' || c == 'i' || c == 'D')
		info->conversion_type = CONV_SIGNED;
	else if (c == 's')
		info->conversion_type = info->conversion_length == CONV_L ?
			CONV_WSTRING : CONV_STRING;
	else if (c == 'S')
		info->conversion_type = CONV_WSTRING;
	else if (c == 'c')
		info->conversion_type = info->conversion_length == CONV_L ?
			CONV_WCHAR : CONV_CHAR;
	else if (c == 'C')
		info->conversion_type = CONV_WCHAR;
	else if (c == 'p')
		info->conversion_type = CONV_POINTER;
	else if (c)
		info->conversion_type = CONV_PERCENT;
	else
		(*i)--;
	if (c == 'U' || c == 'O' || c == 'D')
		info->conversion_length = CONV_L;
}
