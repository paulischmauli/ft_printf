/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 15:28:19 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/18 21:50:20 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list *ap, char identifier)
{
	if (identifier == 'c')
		return (ft_print_char((unsigned char)va_arg(*ap, int)));
	else if (identifier == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	else if (identifier == 'd' || identifier == 'i')
		return (ft_print_signed_number(va_arg(*ap, int), identifier));
	else if (identifier == 'u')
		return (ft_print_number((unsigned long)va_arg(*ap, unsigned int), 10,
				identifier));
	else if (identifier == 'x')
		return (ft_print_number((unsigned long)va_arg(*ap, unsigned int), 16,
				identifier));
	else if (identifier == 'X')
		return (ft_print_number((unsigned long)va_arg(*ap, unsigned int), 16,
				identifier));
	else if (identifier == 'p')
		return (ft_print_pointer(va_arg(*ap, void *), identifier));
	else if (identifier == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		format_error;

	va_start(ap, format);
	count = 0;
	format_error = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format_error = print_format(&ap, *++format);
			if (format_error == -1)
				return (va_end(ap), format_error);
			count += format_error;
		}
		else
			count += write(1, format, 1);
		if (*format)
			format++;
	}
	return (va_end(ap), count);
}
