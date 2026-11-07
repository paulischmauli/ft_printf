int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while ((*str)++)
		;
	return (end - str);
}
