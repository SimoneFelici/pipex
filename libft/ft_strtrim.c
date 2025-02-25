/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:44:09 by sfelici           #+#    #+#             */
/*   Updated: 2024/12/22 18:44:10 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	before(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static int	after(char const *s1, char const *set, int len)
{
	int	i;
	int	j;

	i = len - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_calloc(1, sizeof(char)));
	start = before(s1, set);
	if (start == len)
	{
		return (ft_calloc(1, sizeof(char)));
	}
	end = after(s1, set, len);
	if (end < start)
	{
		return (ft_calloc(1, sizeof(char)));
	}
	string = ft_substr(s1, start, end - start + 1);
	return (string);
}
