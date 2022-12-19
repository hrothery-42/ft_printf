/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:23:54 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/10 12:15:57 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_flag(const char *s, int *i, va_list ap, int sum)
{
	int	j;

	(*i)++;
	j = *i;
	if (s[j] == '%')
		sum = write(1, "%", 1);
	if (s[j] == 'p')
		sum = flag_is_p(va_arg(ap, long unsigned int));
	if (s[j] == 'x')
		sum = ft_hex_lower(va_arg(ap, unsigned int));
	if (s[j] == 'X')
		sum = ft_hex_upper(va_arg(ap, unsigned int));
	if (s[j] == 'c')
		sum = flag_is_c(ap);
	if (s[j] == 'i' || s[j] == 'd')
		sum = flag_is_i(ap);
	if (s[j] == 's')
		sum = flag_is_s(ap);
	if (s[j] == 'u')
		sum = flag_is_u(ap);
	(*i)++;
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		sum;
	int		i;
	va_list	ap;

	if (!s)
		return (0);
	sum = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			sum += read_flag(s, &i, ap, sum);
		else
			sum += print_char(s, &i);
	}
	va_end(ap);
	return (sum);
}
