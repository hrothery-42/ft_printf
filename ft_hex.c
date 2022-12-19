/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:05:20 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/10 10:31:08 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_base16(long int n)
{
	int	x;

	x = 1;
	while (n / 16)
	{
		n /= 16;
		x++;
	}
	return (x);
}

int	ft_hex_upper(unsigned int n)
{
	char	*hex;
	char	*arr;
	int		i;
	int		sum;

	hex = "0123456789ABCDEF";
	arr = (char *)malloc(sizeof(char) * digits_base16(n));
	i = 0;
	sum = 0;
	while (n / 16)
	{
		arr[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	arr[i] = hex[n];
	while (i >= 0)
		sum += write(1, &arr[i--], 1);
	free(arr);
	return (sum);
}

int	ft_hex_lower(unsigned int n)
{
	char	*hex;
	char	*arr;
	int		i;
	int		sum;

	hex = "0123456789abcdef";
	arr = (char *)malloc(sizeof(char) * digits_base16(n));
	i = 0;
	sum = 0;
	while (n / 16)
	{
		arr[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	arr[i] = hex[n];
	while (i >= 0)
		sum += write(1, &arr[i--], 1);
	free(arr);
	return (sum);
}

int	hex_longint(long unsigned int n)
{
	char	*hex;
	char	*arr;
	int		i;
	int		sum;

	hex = "0123456789abcdef";
	arr = (char *)malloc(sizeof(char) * 32);
	if (!arr)
		return (0);
	i = 0;
	sum = 0;
	while (n / 16)
	{
		arr[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	arr[i] = hex[n];
	while (i >= 0)
		sum += write(1, &arr[i--], 1);
	free(arr);
	return (sum);
}

int	flag_is_p(long unsigned int n)
{
	int	sum;

	sum = 0;
	sum += write(1, "0x", 2);
	if (n == 0)
		sum += write(1, "0", 1);
	else
		sum += hex_longint(n);
	return (sum);
}

/* int	main(void)
{
	int	i = 5;
	void	*pointer = &i;
	unsigned long int	p = (unsigned long int)pointer;
	printf("prinft %x", 3735929054u);
	ft_hex_upper(p);
	write(1, "\n", 1);
	return (0);
}
 */