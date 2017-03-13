/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:12:22 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/03 14:52:43 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PADDING_H
# define PADDING_H

# include "format.h"

void	pad_left(t_format *info);
void	pad_right(t_format *info);
void	pad_zero(int l, int sign, t_format *info);

#endif
