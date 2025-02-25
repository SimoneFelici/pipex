/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:15:33 by sfelici           #+#    #+#             */
/*   Updated: 2024/12/15 18:15:35 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*src;
	unsigned char	chr;

	src = (unsigned char *)buf;
	chr = (unsigned char)c;
	while (count-- > 0)
	{
		if (*src == chr)
			return (src);
		src++;
	}
	return (NULL);
}
