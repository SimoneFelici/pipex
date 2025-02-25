/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:41:01 by sfelici           #+#    #+#             */
/*   Updated: 2024/12/23 13:21:34 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	copy_string(char *dest, const char *src, size_t *i)
{
	while (*src)
	{
		dest[*i] = *src;
		(*i)++;
		src++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	i = 0;
	copy_string(string, s1, &i);
	copy_string(string, s2, &i);
	string[i] = '\0';
	return (string);
}
