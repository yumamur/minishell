/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_office.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:28 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 17:08:34 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env_util.h"
#include "lpc.h"
#include <stdlib.h>

char	*ft_space(char *s)
{
	int		a;
	int		i;
	char	*sa;

	a = ft_strlen(s);
	i = -1;
	sa = malloc(a + 1);
	if (!sa)
		return (NULL);
	lpc_export(sa, NULL);
	while (++i < a)
		sa[i] = ' ';
	sa[i] = '\0';
	return (sa);
}

char	*exchanger(char *arg, int i, int t_s)
{
	int			tmp;
	char		*r;
	char		*r2;
	const char	*dollar_value;

	r2 = ft_strdup("");
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
			r = ft_strjoin(ft_substr(arg, t_s, tmp - t_s -1), dollar_value);
			r2 = ft_strjoin(r2, r);
			t_s = i;
			if (!ft_strchr(arg + i, '$'))
				r2 = ft_strjoin(r2, ft_substr(arg, i, ft_strlen(arg)));
		}
		i++;
	}
	return (r2);
}

char	*dollar_check(char *arg)
{
	if (arg[0] == '\'')
		return (arg);
	return (exchanger(arg, 0, 0));
}
