/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:51:06 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 14:57:34 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <stdarg.h>
# include <stdlib.h>

# define ALTERNATE_FORM	0x01
# define ZERO_PADDING	0x02
# define RIGHT_PADDING	0x04
# define BLANK_SIGN		0x08
# define PLUS_SIGN		0x10
# define FORCE_SIGN		(BLANK_SIGN | PLUS_SIGN)

typedef struct	s_format
{
	int		written;
	int		length;
	int		width;
	int		precision;
	char	flags;
	char	conversion_length;
	char	conversion_type;
	char	conversion_format;
}				t_format;

int				print_formatted(const char *fmt, va_list args, size_t *i);

#endif
