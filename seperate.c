#include "parse.h"
#define NULL 0

int is_double_seperator_in(t_c_char *str)
{
	t_c_char **seperators_d;
	int i;

	seperators_d = malloc(sizeof(char *) * 5);
	seperators_d[0] = ft_strdup("||");
	seperators_d[1] = ft_strdup("<<");
	seperators_d[2] = ft_strdup(">>");
	seperators_d[3] = ft_strdup("&&");
	seperators_d[4] = NULL;

	i = 0;
	while (seperators_d[i])
	{
		if (!ft_strncmp(seperators_d[i], str, 2))
			return (1);
		i++;
	}
	return (0);
}

int is_seperator_in(t_c_char *str)
{
	t_c_char **seperators;
	int i;

	seperators = malloc(sizeof(char *) * 4);
	seperators[0] = ft_strdup("|");
	seperators[1] = ft_strdup("<");
	seperators[2] = ft_strdup(">");
	seperators[3] = NULL;	

	i = 0;
	while (seperators[i])
	{
		if (!ft_strncmp(seperators[i], str, 1))
			return (1);
		i++;
	}
	return (0);
}

int is_seperator(t_c_char *strr)
{
	// "asd"asd||asd"asd"
	// stringin icinde gecerli bir ayirici(cift tirnak veya tek tirnak icinde olmayan redirections ve pipe) varsa 1 dondur
	char *str;
	int i;
	int quote;

	str = (char *)strr;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == 34 || str[i] == 39) && quote == 0)
		{
			quote = str[i];
			i++;
			continue;
		}
		if (quote != 0 && quote == str[i])
			quote = 0;
		if (quote == 0 && str[i + 1] && is_double_seperator_in(&str[i]))
			return (2);
		else if (quote == 0 && str[i] && is_seperator_in(&str[i]))
			return (1);
		i++;
	}
	return (0);
}