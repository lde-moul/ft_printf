/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:33:59 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/08 14:47:57 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "format.h"
# include <stdlib.h>

# define CONV_NONE				0

# define CONV_HH				1
# define CONV_H					2
# define CONV_L					3
# define CONV_LL				4
# define CONV_J					5
# define CONV_Z					6

# define CONV_UNSIGNED			1
# define CONV_SIGNED			2
# define CONV_STRING			3
# define CONV_WSTRING			4
# define CONV_CHAR				5
# define CONV_WCHAR				6
# define CONV_POINTER			7
# define CONV_PERCENT			8

# define CONV_OCTAL				1
# define CONV_HEXADECIMAL		2
# define CONV_HEXADECIMAL_UPPER	3

void	check_conversion(const char *fmt, size_t *i, t_format *info);

#endif
