/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:08:30 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/05 11:07:12 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const char *s, int *i)
{
	int	k;
	int	sum;

	k = *i;
	sum = write(1, &s[k], 1);
	(*i)++;
	return (sum);
}

int	flag_is_c(va_list ap)
{
	unsigned char	c;
	int				sum;

	c = va_arg(ap, int);
	sum = write(1, &c, 1);
	return (sum);
}

int	flag_is_i(va_list ap)
{
	int		sum;
	char	*str;

	str = ft_itoa(va_arg(ap, int));
	sum = write(1, str, ft_strlen(str));
	free (str);
	return (sum);
}

int	flag_is_s(va_list ap)
{
	int		sum;
	char	*str;

	sum = 0;
	str = va_arg(ap, char *);
	if (!str)
		sum = write(1, "(null)", 6);
	else
		sum = write(1, str, ft_strlen(str));
	return (sum);
}

int	flag_is_u(va_list ap)
{
	int				sum;
	unsigned int	ui;
	char			*str;

	sum = 0;
	ui = va_arg(ap, unsigned int);
	str = itoa_unsigned(ui);
	sum = write(1, str, ft_strlen(str));
	free(str);
	return (sum);
}
