#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include "libft/libft.h"

int	control(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			(i)++;
			while (str[i] && str[i] != '\'')
			{
				(i)++;
				if (str[i] == '\t')
					str[i] = -2;
				else if (str[i] == ' ')
					str[i] = -3;
			}
			if (str[i] == '\'' && (i)++)
				return (1);
			else
				return (0);
		}
		else if (str[i] == '"')
		{
			(i)++;
			while (str[i] && str[i] != '"')
			{
				(i)++;
				if (str[i] == '\t')
					str[i] = -2;
				else if (str[i] == ' ')
					str[i] = -3;
			}
			if (str[i] == '"' && (i)++)
				return (1);
			else
				return (0);
		}
		break ;
	}
	return (0);
}

static int	count_words(char *str)
{
	int	ret;
	int a = 0;

	ret = 0;
	while (*str)
	{
		printf("%s %d\n", str, a++);
		while (*str == '\t' || *str == ' ')
			++str;
		if (*str == '\"' || *str == '\'')
		{
			if (control(str) == 1)
			{
				printf("kalem : \n");
				ret++;
				str = ft_strchr(str + 1, *str) + 1;
			}
			else
			{
				printf("elma armut\n");
				return (0);
			}
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
	if (ct_word == 0)
	{
		ft_putendl_fd("minishell : parse error", STDOUT_FILENO);
		return (0);
	}	
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
