/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:08:12 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/10 17:45:37 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	txt;

	txt = 0;
	if (!str)
	{
		txt += ft_putstr("(null)");
		return (txt);
	}
	i = 0;
	while (str[i] != '\0')
	{
		txt += ft_putchar(str[i]);
		i++;
	}
	return (txt);
}

int	ft_format(va_list args, char c)
{
	int	lenght;

	lenght = 0;
	if (c == 'c')
		lenght = ft_putchar(va_arg(args, int));
	else if (c == 's')
		lenght = ft_putstr(va_arg(args, void *));
	else if (c == 'p')
		lenght = ft_putp(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		lenght = ft_putnb(va_arg(args, int));
	else if (c == 'u')
		lenght = ft_putnb(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		lenght = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		lenght = ft_putchar('%');
	return (lenght);
}

int	ft_printf(char const *input, ...)
{
	va_list	args;
	int		chars;
	int		i;

	chars = 0;
	i = 0;
	if (!input)
		return (0);
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			chars += ft_format(args, input[i]);
		}
		else
			chars += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (chars);
}
