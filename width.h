/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:16:25 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:24:12 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDTH_H
# define WIDTH_H

# include "format.h"
# include <stdarg.h>
# include <stdlib.h>

void	check_width(const char *fmt, va_list args, size_t *i, t_format *info);

#endif
