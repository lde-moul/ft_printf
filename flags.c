/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:03:30 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:01:53 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <stdlib.h>

void	check_flags(const char *fmt, size_t *i, char *flags)
{
	*flags = 0;
	while (1)
	{
		if (fmt[*i] == '#')
			*flags |= ALTERNATE_FORM;
		else if (fmt[*i] == '0')
			*flags |= ZERO_PADDING;
		else if (fmt[*i] == '-')
			*flags |= RIGHT_PADDING;
		else if (fmt[*i] == ' ')
			*flags |= BLANK_SIGN;
		else if (fmt[*i] == '+')
			*flags |= PLUS_SIGN;
		else
			break ;
		(*i)++;
	}
}
