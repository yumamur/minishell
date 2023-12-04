int	ft_isalnum(int c);

int ft_isalnum_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			i++;
		else
			return(0);
	}
	return(1);
}