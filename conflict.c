/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conflict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:13:13 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 13:52:41 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

void	check_conflicts(t_format *info)
{
	if (info->precision != -1
	&& (info->conversion_type == CONV_CHAR
	|| info->conversion_type == CONV_PERCENT))
		info->precision = -1;
	if (info->flags & ZERO_PADDING
	&& (info->flags & info->flags & RIGHT_PADDING || info->precision != -1)
	&& info->conversion_type != CONV_STRING
	&& info->conversion_type != CONV_WSTRING)
		info->flags &= ~ZERO_PADDING;
}
