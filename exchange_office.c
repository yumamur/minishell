int	contains_var(char *str)
{
	if (*str == '$')
		return (1);
	else if (*str != '\"')
		return (0);
	while (*str)
	{
		if (*str == '$')
			return (1);
		++str;
	}
	return (0);
}

char	*env_var_extension(char *str)
{
	char	(*arr)[3];

	if (*str == '\'' || !contains_var(str))
		return (str);
	if (*str == '$')
		replace_str(str, );
}
