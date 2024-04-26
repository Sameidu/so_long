/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:08:08 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/10 17:08:59 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(long nb)
{
	int	check;
	int	len;

	len = 0;
	check = 0;
	if (nb >= 10)
		len = ft_digits(nb / 10);
	check = ft_putchar(nb % 10 + 48);
	len += check;
	return (len);
}

int	ft_putnb(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len = ft_putchar('-');
	}
	len += ft_digits(nb);
	return (len);
}

int	ft_puthex(size_t nb, char c)
{
	int		i;
	int		len;
	char	string[17];
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	i = 0;
	len = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb != 0)
	{
		string[i++] = hex[nb % 16];
		nb /= 16;
	}
	while (i > 0)
	{
		if (ft_putchar(string[--i]) < 0)
			return (-1);
		else
			len++;
	}
	return (len);
}

int	ft_putp(void *ptr)
{
	int	i;

	i = ft_putstr("0x");
	i += ft_puthex((size_t)ptr, 'x');
	return (i);
}
