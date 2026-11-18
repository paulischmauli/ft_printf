/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_formats.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 19:18:35 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/18 18:58:31 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	letta;

	letta = (unsigned char)c;
	return (write(1, &letta, 1));
}

int	ft_print_string(char *s)
{
	size_t	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = -1;
	while (s[++len])
		;
	return (write(1, s, len));
}

int	ft_print_pointer(void *pointer, char identifier)
{
	int				count;
	unsigned long	nbr;

	nbr = (unsigned long)pointer;
	count = 0;
	if (!nbr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	return (count += ft_print_number(nbr, 16, identifier));
}

int	ft_print_signed_number(int nbr, char identifier)
{
	int				count;
	unsigned long	number;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		number = -(unsigned long)nbr;
	}
	else
		number = (unsigned long)nbr;
	return (count += ft_print_number(number, 10, identifier));
}

int	ft_print_number(unsigned long nbr, unsigned long base, char identifier)
{
	int		count;
	char	*set;
	char	*set_up;

	set = "0123456789abcdef";
	set_up = "0123456789ABCDEF";
	count = 0;
	if (nbr >= base)
		count += ft_print_number(nbr / base, base, identifier);
	if (identifier == 'X')
		return (count += write(1, &set_up[nbr % base], 1));
	else
		return (count += write(1, &set[nbr % base], 1));
}
