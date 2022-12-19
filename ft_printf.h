/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:39:16 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/05 11:05:54 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
int		ft_hex_lower(unsigned int n);
int		ft_hex_upper(unsigned int n);
char	*ft_itoa(int n);
int		flag_is_p(long unsigned int n);
int		hex_longint(long unsigned int n);
int		read_flag(const char *s, int *i, va_list ap, int sum);
int		print_char(const char *s, int *i);
int		flag_is_c(va_list ap);
int		flag_is_i(va_list ap);
int		flag_is_s(va_list ap);
int		flag_is_u(va_list ap);
char	*itoa_unsigned(unsigned int n);

#endif