/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:56 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/28 00:38:22 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_h(unsigned long int nb, unsigned long int b)
{
	int	i;

	i = 1;
	while (nb >= b)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	hex(unsigned long int n, char *base)
{
	if (n < ft_strlen2(base))
	{
		ft_putchar(base[n]);
	}
	if (n >= ft_strlen2(base))
	{
		hex(n / ft_strlen2(base), base);
		hex(n % ft_strlen2(base), base);
	}
	return (ft_count_h(n, ft_strlen2(base)));
}

int	ft_check(char c, va_list arg)
{
	void	*p;

	if (c == 's')
		return (ft_putstr((char *)va_arg(arg, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (hex(va_arg(arg, unsigned int), "0123456789"));
	if (c == 'x')
		return (hex(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (hex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
	{
		p = va_arg(arg, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + hex((unsigned long int)p,
				"0123456789abcdef"));
	}
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
			count += ft_check(s[++i], arg);
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
