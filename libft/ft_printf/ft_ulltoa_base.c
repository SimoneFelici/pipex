/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:59 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:36:00 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ull_digits_base(unsigned long long n, int base_len)
{
	int	count;

	count = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

char	*ft_ulltoa_base(unsigned long long n, const char *base_str)
{
	int		base_len;
	int		digits;
	char	*str;

	base_len = 0;
	while (base_str[base_len])
		base_len++;
	digits = count_ull_digits_base(n, base_len);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--digits] = base_str[n % base_len];
		n /= base_len;
	}
	return (str);
}
