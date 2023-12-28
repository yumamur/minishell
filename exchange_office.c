/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_office.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:28 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/14 14:35:01 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env_util.h"
#include <stdlib.h>

char	*ft_space(char *s)
{
	int		a;
	int		i;
	char	*sa;

	a = ft_strlen(s);
	i = -1;
	sa = malloc(a + 1);
	while (++i < a)
		sa[i] = ' ';
	sa[i] = '\0';
	return (sa);
}

char	*exchanger(char *arg)
{
	int			tmp;
	int			tmp_start;
	int			i;
	char		*result;
	char		*result2;
	const char	*dollar_value;

	result2 = ft_strdup("");
	i = 0;
	tmp_start = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			tmp = ++i;
			while (arg[i] && arg[i] != '$' && arg[i] != ' ' && arg[i] != '\"')
				++i;
			dollar_value = ft_getenv(ft_substr(arg, tmp, i - tmp));
			if (!dollar_value)
				dollar_value = ft_space(ft_substr(arg, tmp - 1, i - tmp));
			result = ft_strjoin(ft_substr(arg, tmp_start,
						tmp - tmp_start -1), dollar_value);
			result2 = ft_strjoin(result2, result);
			tmp_start = i;
			if (!ft_strchr(arg + i, '$'))
				result2 = ft_strjoin(result2,
						ft_substr(arg, i, ft_strlen(arg)));
		}
		i++;
	}
	return (result2);
}

char	**dollar_check(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == '\'')
			i++;
		else if (ft_strchr(arg[i], '$'))
			arg[i] = exchanger(arg[i]);
		i++;
	}
	return (arg);
}
