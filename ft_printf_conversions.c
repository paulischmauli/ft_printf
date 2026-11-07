#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
		return (write(1,"(null)"), 6);
	return(write(1, s, ft_strlen(s)));
}
