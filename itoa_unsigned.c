/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:08:29 by hrothery          #+#    #+#             */
/*   Updated: 2022/01/05 11:19:25 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*itoa_str(char *s, unsigned int n, int i)
{
	s[i--] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char	*itoa_unsigned(unsigned int n)
{
	char			*out_str;
	unsigned int	nbr;

	nbr = n;
	out_str = (char *)malloc((len(n) + 1) * sizeof(char));
	if (!out_str)
		return (NULL);
	out_str = itoa_str(out_str, nbr, len(n));
	return (out_str);
}

/* int	main(void)
{
	unsigned int	ui;

	ui = 4294967295;
	printf("len of n is %d\n", len(numuiber));
	printf("The char string %d is %s\n", ui, itoa_unsigned(ui));
	return (0);
}
 */