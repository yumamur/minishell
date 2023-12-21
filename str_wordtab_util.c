/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_wordtab_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:37:54 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/21 15:50:39 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int	is_special_or_quote(char c, int q_s)
{
	if ((q_s == 1) && (c == '|' || c == '&' || c == '<' || c == '>'))
		return (1);
	else if ((q_s == 0) && (c == '\"' || c == '\''))
		return (1);
	return (0);
}

int	token_control(const char *str, int i)
{
	if (!ft_strncmp(str + i, "||", 2)
		|| !ft_strncmp(str + i, "&&", 2)
		|| !ft_strncmp(str + i, "<<", 2)
		|| !ft_strncmp(str + i, ">>", 2))
		return (1);
	return (0);
}

int	create_new_str(const char *str)
{
	int	len;
	int	i;
	int	in_quote;

	len = 0;
	i = 0;
	in_quote = 0;
	while (str[i])
	{
		if (is_special_or_quote(str[i], 0) == 1)
			in_quote = !in_quote;
		if (!in_quote && (token_control(str, i)))
			len += 4;
		else if (!in_quote && is_special_or_quote(str[i], 1) == 1)
			len += 3;
		else
			len++;
		i++;
	}
	return (len + 1);
}


char	*str_update(const char *str, int in_quote, int i, int j)
{
	char *new_str;

	new_str = malloc(create_new_str(str));
	while (str[i])
	{
		if (is_special_or_quote(str[i], 0))
			in_quote = !in_quote;
		if (!in_quote && token_control(str, i) == 1)
		{
			if (i > 0 && str[i - 1] != ' ')
				new_str[j++] = ' ';
			new_str[j++] = str[i++];
			new_str[j++] = str[i++];
			if (str[i] != ' ' && str[i] != '\0')
				new_str[j++] = ' ';
		}
		else if (!in_quote && is_special_or_quote(str[i], 1))
		{
			if (i > 0 && str[i - 1] != ' ')
				new_str[j++] = ' ';
			new_str[j++] = str[i++];
			if (str[i] != ' ' && str[i] != '\0' && !is_special_or_quote(str[i], 1))
				new_str[j++] = ' ';
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return new_str;
}

char	*add_spaces(const char *str)
{
	char	*new_str;
	int		i;
	int		j;
	int		in_quote;

	i = 0;
	j = 0;
	in_quote = 0;
	new_str = str_update(str, in_quote, i, j);
	return (new_str);
}
