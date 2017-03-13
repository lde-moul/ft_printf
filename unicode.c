/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:36:57 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:13:40 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"
#include <unistd.h>
#include <stdlib.h>

static int	print_unicode_2_bytes(wchar_t c)
{
	int b;

	b = 0xc080 | ((c & 0x7c0) << 2) | (c & 0x3f);
	b = (b >> 8) | ((b & 0xff) << 8);
	return (write(1, &b, 2));
}

static int	print_unicode_3_bytes(wchar_t c)
{
	int b;

	b = 0xe08080 | ((c & 0xf000) << 4) | ((c & 0xfc0) << 2) | (c & 0x3f);
	b = (b >> 16) | (b & 0xff00) | ((b & 0xff) << 16);
	return (write(1, &b, 3));
}

static int	print_unicode_4_bytes(wchar_t c)
{
	int b;

	b = 0xf0808080 | ((c & 0x1c0000) << 6) | ((c & 0x3f000) << 4)
		| ((c & 0xfc0) << 2) | (c & 0x3f);
	b = (b >> 24) | ((b & 0xff0000) >> 8)
		| ((b & 0xff00) << 8) | ((b & 0xff) << 24);
	return (write(1, &b, 4));
}

int			print_unicode(wchar_t c)
{
	if (MB_CUR_MAX == 1 && c > 255)
		return (-1);
	if (MB_CUR_MAX == 1 && c > 127)
		c = (char)c;
	if (c < 128)
		return (write(1, &c, 1));
	else if (c < 2048)
		return (print_unicode_2_bytes(c));
	else if (c < 65536)
		return (print_unicode_3_bytes(c));
	else if (c < 2097152)
		return (print_unicode_4_bytes(c));
	return (-1);
}

int			wchar_bytes(wchar_t c)
{
	if (c < 128)
		return (1);
	else if (MB_CUR_MAX == 1 && c > 255)
		return (0);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	return (0);
}
