/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:11 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:35:12 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		done;

	va_start(args, format);
	i = 0;
	done = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			done += ft_handle_format(format[i], args);
		}
		else
		{
			done += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (done);
}
