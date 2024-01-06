void	str_update_util2(const char *str, int *i, char *new_str, int *j)
{
	if (*i && str[*i - 1] != ' ')
		new_str[(*j)++] = ' ';
	new_str[(*j)++] = str[(*i)++];
	new_str[(*j)++] = str[(*i)++];
	if (str[*i] != ' ' && str[*i] != '\0')
		new_str[(*j)++] = ' ';
}
