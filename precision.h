/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:18:08 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 18:03:51 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECISION_H
# define PRECISION_H

# include <stdarg.h>
# include <stdlib.h>

void	check_precision(const char *fmt, va_list args, size_t *i, int *prec);

#endif
