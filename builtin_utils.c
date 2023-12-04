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

int	export_isenv(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);

}