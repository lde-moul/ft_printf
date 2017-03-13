/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:46:56 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:25:18 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "flags.h"
#include "width.h"
#include "precision.h"
#include "conversion.h"
#include "conflict.h"
#include "print_decimal.h"
#include "print_hexadecimal.h"
#include "print_octal.h"
#include "print_signed.h"
#include "print_string.h"
#include "print_wstring.h"
#include "print_char.h"
#include "print_wchar.h"
#include "print_pointer.h"

static void	print_formatted_unsigned(va_list args, t_format *info)
{
	uintmax_t n;

	if (info->conversion_length == CONV_HH)
		n = (unsigned char)va_arg(args, int);
	else if (info->conversion_length == CONV_H)
		n = (unsigned short)va_arg(args, int);
	else if (info->conversion_length == CONV_L)
		n = va_arg(args, unsigned long);
	else if (info->conversion_length == CONV_LL)
		n = va_arg(args, unsigned long long);
	else if (info->conversion_length == CONV_J)
		n = va_arg(args, uintmax_t);
	else if (info->conversion_length == CONV_Z)
		n = va_arg(args, size_t);
	else
		n = va_arg(args, unsigned int);
	if (info->conversion_format == CONV_NONE)
		print_decimal(n, info);
	else if (info->conversion_format == CONV_OCTAL)
		print_octal(n, info);
	else
		print_hexadecimal(n, info);
}

static void	print_formatted_signed(va_list args, t_format *info)
{
	if (info->conversion_length == CONV_HH)
		print_signed((signed char)va_arg(args, int), info);
	else if (info->conversion_length == CONV_H)
		print_signed((short)va_arg(args, int), info);
	else if (info->conversion_length == CONV_L)
		print_signed(va_arg(args, long), info);
	else if (info->conversion_length == CONV_LL)
		print_signed(va_arg(args, long long), info);
	else if (info->conversion_length == CONV_J)
		print_signed(va_arg(args, intmax_t), info);
	else if (info->conversion_length == CONV_Z)
		print_signed(va_arg(args, size_t), info);
	else
		print_signed(va_arg(args, int), info);
}

int			print_formatted(const char *fmt, va_list args, size_t *i)
{
	t_format	info;

	(*i)++;
	check_flags(fmt, i, &info.flags);
	check_width(fmt, args, i, &info);
	check_precision(fmt, args, i, &info.precision);
	check_conversion(fmt, i, &info);
	check_conflicts(&info);
	if (info.conversion_type == CONV_UNSIGNED)
		print_formatted_unsigned(args, &info);
	else if (info.conversion_type == CONV_SIGNED)
		print_formatted_signed(args, &info);
	else if (info.conversion_type == CONV_STRING)
		print_string(va_arg(args, char*), &info);
	else if (info.conversion_type == CONV_WSTRING)
		print_wstring(va_arg(args, wchar_t*), &info);
	else if (info.conversion_type == CONV_CHAR)
		print_char((unsigned char)va_arg(args, int), &info);
	else if (info.conversion_type == CONV_WCHAR)
		print_wchar(va_arg(args, wchar_t), &info);
	else if (info.conversion_type == CONV_POINTER)
		print_pointer((size_t)va_arg(args, void*), &info);
	else if (info.conversion_type == CONV_PERCENT)
		print_char(fmt[*i], &info);
	return (info.written);
}
