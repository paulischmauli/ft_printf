/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_formats.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 19:18:35 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/14 20:15:20 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_print_number(long long nbr, int base, char identifier)
{
	int		count;
	char	*set;
	char	*set_up;

	set = "0123456789abcdef";
	set_up = "0123456789ABCDEF";
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		ft_print_number(-nbr, base, identifier);
	}
}
