#include <stdlib.h>
#include "libft/libft.h"

int	control(char *str)
{
	if (*str == '\"' && ft_strchr(str, '\"'))
	{
		while (*++str && *str != '\"')
		{
			if (*str == '\t')
				*str = -2;
			else if (*str == ' ')
				*str = -3;
		}
		return (1);
	}
	else if (*str == '\'' && ft_strchr(str, '\''))
	{
		while (*++str && *str != '\'')
		{
			if (*str == '\t')
				*str = -2;
			else if (*str == ' ')
				*str = -3;
		}
		return (1);
	}
	return (0);
}

static int	count_words(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		while (*str == '\t' || *str == ' ')
			++str;
		if (*str == '\"' || *str == '\'')
		{
			if (control(str) == 1)
			{
				ret++;
				str = ft_strchr(str + 1, *str) + 1;
			}
			else
				return (0);
		}
		if (*str)
			++ret;
		while (*str && *str != '\t' && *str != ' ' 
			&& *str != '\"' && *str != ' ')
			++str;
	}
	return (ret);
}

static void	fixer(char	**str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while ((*str)[i])
		{
			if ((*str)[i] == -2)
				(*str)[i] = '\t';
			else if ((*str)[i] == -3)
				(*str)[i] = ' ';
			i++;
		}
		str++;
	}
}

char	**ft_str_wordtab(char *str)
{
	char	**ret;
	int		ct_word;

	ct_word = count_words(str);
	ret = malloc(++ct_word * sizeof(char *));
	if (!ret)
		return (0);
	ct_word = 0;
	while (*str)
	{
		while ((*str == '\t' || *str == ' '))
			*str++ = 0;
		if (*str)
			ret[ct_word++] = str;
		while (*str && *str != '\t' && *str != ' ')
			++str;
	}
	ret[ct_word] = 0;
	fixer(ret);
	return (ret);
}
