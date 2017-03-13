/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:31:22 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:13:52 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"
#include "padding.h"

static void	print_wstring_normal(wchar_t *s, t_format *info)
{
	int i;
	int b;

	i = 0;
	info->length = 0;
	while (s[i])
	{
		b = wchar_bytes(s[i++]);
		info->length += b;
		if (!b)
			return ;
	}
	pad_left(info);
	if (info->flags & ZERO_PADDING)
		pad_zero(info->length, 0, info);
	while (*s)
		info->written += print_unicode(*(s++));
	pad_right(info);
}

static void	print_wstring_precision(wchar_t *s, t_format *info)
{
	int i;
	int b;

	i = 0;
	info->length = 0;
	while (s[i] && info->length + (b = wchar_bytes(s[i++])) <= info->precision)
	{
		if (!b)
			return ;
		info->length += b;
	}
	if (info->flags & ZERO_PADDING)
		info->precision = -1;
	pad_left(info);
	if (info->flags & ZERO_PADDING)
		pad_zero(info->length, 0, info);
	i = 0;
	while (*s && i + wchar_bytes(*s) <= info->precision)
	{
		b = print_unicode(*(s++));
		info->written += b;
		i += b;
	}
	pad_right(info);
}

void		print_wstring(wchar_t *s, t_format *info)
{
	if (!s)
		s = L"(null)";
	if (info->precision == -1)
		print_wstring_normal(s, info);
	else
		print_wstring_precision(s, info);
}
