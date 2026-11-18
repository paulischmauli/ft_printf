/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 15:27:25 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/18 21:51:21 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(unsigned char c);
int	ft_print_number(unsigned long nbr, unsigned long base, char identifier);
int	ft_print_pointer(void *pointer, char identifier);
int	ft_print_signed_number(int nbr, char identifier);
int	ft_print_string(char *s);
int	ft_printf(const char *format, ...);
int	print_format(va_list *ap, char identifier);

#endif
