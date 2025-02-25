/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:50 by sfelici           #+#    #+#             */
/*   Updated: 2025/01/18 14:35:52 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);

int		ft_handle_format(char c, va_list args);

int		ft_handle_char(va_list args);
int		ft_handle_str(va_list args);
int		ft_handle_digit(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hex(va_list args, const char *base);
int		ft_handle_ptr(va_list args);

int		ft_print_char(char c);
int		ft_print_str(const char *str);
int		ft_print_digit(const char *str);

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, const char *base_str);
char	*ft_ulltoa_base(unsigned long long n, const char *base_str);

#endif
