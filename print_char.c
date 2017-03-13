/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:14:12 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 14:33:36 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "padding.h"
#include "format.h"
#include <unistd.h>

void	print_char(unsigned char c, t_format *info)
{
	info->length = 1;
	pad_left(info);
	pad_zero(1, 0, info);
	info->written += write(1, &c, 1);
	pad_right(info);
}
