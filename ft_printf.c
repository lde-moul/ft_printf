/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:28:04 by lde-moul          #+#    #+#             */
/*   Updated: 2017/03/13 15:00:38 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <unistd.h>

static int	print_main(const char *fmt, va_list args)
{
	int		written;
	size_t	i;
	size_t	n;

	written = 0;
	i = 0;
	n = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			n++;
		else
		{
			if (n)
				written += write(1, fmt + i - n, n);
			if ((n = print_formatted(fmt, args, &i)) == -1)
				return (-1);
			written += n;
			n = 0;
		}
		i++;
	}
	if (n)
		written += write(1, fmt + i - n, n);
	return (written);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		written;

	va_start(args, format);
	written = print_main(format, args);
	va_end(args);
	return (written);
}
