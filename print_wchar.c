/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:49:27 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 16:37:15 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"
#include "padding.h"

void	print_wchar(wchar_t c, t_format *info)
{
	info->length = wchar_bytes(c);
	if (!info->length)
		return ;
	pad_left(info);
	info->written += print_unicode(c);
	pad_right(info);
}
