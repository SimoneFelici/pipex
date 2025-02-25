/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:28 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:35:29 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_digit(va_list args)
{
	char	*str;
	int		len;
	int		n;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_digit(str);
	free(str);
	return (len);
}
