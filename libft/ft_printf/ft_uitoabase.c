/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:19 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:35:20 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits_base(unsigned int n, int len)
{
	int	count;

	count = 1;
	while (n >= (unsigned int)len)
	{
		n /= len;
		count++;
	}
	return (count);
}

char	*ft_uitoa_base(unsigned int n, const char *base_str)
{
	char	*str;
	int		len;
	int		digits;

	len = 0;
	while (base_str[len] != '\0')
		len++;
	digits = count_digits_base(n, len);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--digits] = base_str[n % len];
		n /= len;
	}
	return (str);
}
