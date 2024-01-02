/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:30 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/02 17:39:10 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include "libft/libft.h"

int		quote_control(char *str);
char	*str_update(const char *str);

char	*add_spaces(const char *str)
{
	char	*new_str;

	new_str = str_update(str);
	return (new_str);
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
			if (quote_control(str) == 1)
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
			&& *str != '\"' && *str != '\'' && *str != ' ')
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
	char	*s[2];

	s[0] = add_spaces(str);
	ct_word = count_words(s[0]);
	if (!ct_word)
		return (NULL);
	s[1] = s[0];
	ret = malloc(++ct_word * sizeof(char *));
	if (!ret)
		return (0);
	ct_word = 0;
	while (*(s[0]))
	{
		while ((*(s[0]) == '\t' || *(s[0]) == ' '))
			*(s[0])++ = 0;
		if (*(s[0]))
			ret[ct_word++] = s[0];
		while (*(s[0]) && *(s[0]) != '\t' && *(s[0]) != ' ')
			++(s[0]);
	}
	ret[ct_word] = 0;
	fixer(ret);
	return (ret);
}
