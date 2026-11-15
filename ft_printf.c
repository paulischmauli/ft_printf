/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 15:28:19 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/14 20:16:22 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list *ap, char identifier)
{
	if (identifier == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (identifier == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	else if (identifier == 'd' || identifier == 'i')
		return (ft_print_number);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(&ap, *(++format));
		else
			count += write(1, format, 1);
		format++;
	}
	return (va_end(ap), count);
}
