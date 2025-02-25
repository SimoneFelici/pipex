/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:36:26 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:36:28 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_handle_char(args));
	if (c == 's')
		return (ft_handle_str(args));
	if (c == 'd' || c == 'i')
		return (ft_handle_digit(args));
	if (c == 'u')
		return (ft_handle_unsigned(args));
	if (c == 'x')
		return (ft_handle_hex(args, "0123456789abcdef"));
	if (c == 'X')
		return (ft_handle_hex(args, "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_handle_ptr(args));
	if (c == '%')
		return (ft_print_char('%'));
	return (ft_print_char(c));
}
