/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:36:34 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:36:35 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_print_str("(null)"));
	return (ft_print_str(str));
}
