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

int is_special_char(char c)
{
    return (c == '|' || c == '&' || c == '<' || c == '>');
}

int is_quote(char c)
{
    return (c == '\"' || c == '\'');
}

char *create_new_str(const char *str)
{
    int len = 0;
    int i = 0;
    int in_quote = 0;

    while (str[i])
    {
        if (is_quote(str[i]))
            in_quote = !in_quote;
        if (!in_quote && ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '&' && str[i + 1] == '&') ||
            (str[i] == '<' && str[i + 1] == '<') || (str[i] == '>' && str[i + 1] == '>')))
            len += 3;
        else if (!in_quote && is_special_char(str[i]))
            len += 2;
        else
            len++;
        i++;
    }
    return (malloc(sizeof(char) * (len + 1)));
}

char *add_spaces(const char *str)
{
    char *new_str = create_new_str(str);
    int i = 0, j = 0, in_quote = 0;

    if (!new_str)
        return (NULL);
    while (str[i])
    {
        if (is_quote(str[i]))
            in_quote = !in_quote;
        if (!in_quote && ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '&' && str[i + 1] == '&') ||
            (str[i] == '<' && str[i + 1] == '<') || (str[i] == '>' && str[i + 1] == '>')))
        {
            if (i > 0 && str[i - 1] != ' ')
                new_str[j++] = ' ';
            new_str[j++] = str[i++];
            new_str[j++] = str[i++];
            if (str[i] != ' ' && str[i] != '\0')
                new_str[j++] = ' ';
        }
        else if (!in_quote && is_special_char(str[i]))
        {
            if (i > 0 && str[i - 1] != ' ')
                new_str[j++] = ' ';
            new_str[j++] = str[i++];
            if (str[i] != ' ' && str[i] != '\0' && !is_special_char(str[i]))
                new_str[j++] = ' ';
        }
        else
            new_str[j++] = str[i++];
    }
    new_str[j] = '\0';
    return (new_str);
}


char	**ft_str_wordtab(char *str)
{
	char	**ret;
	int		ct_word;

	str = add_spaces(str);
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