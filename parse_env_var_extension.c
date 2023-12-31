/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:46:07 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/31 13:46:03 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_util.h"
#include "libft/libft.h"

static int	contains_var(char *str)
{
	if (*str == '$')
		return (1);
	while (*str)
	{
		if (*str == '$')
			return (1);
		++str;
	}
	return (0);
}

static char	*find_end_of_var_name(char *str)
{
	char	*ptr;

	if (!ft_isalpha(*str) || *str != '_')
		return (ptr);
	while (*str && *)
}

static char	*parse_quoted_str(char *str)
{
	t_list	*head;
	char	*ptr;

	while (contains_var(str))
	{
		ptr = ft_strchr(str, '$');
		*ptr = 0;
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(str)));
		*ptr = '$';
		str = find_end_of_var_name(ptr);
	}
	return (str);
}

char	*env_variable_extension(char *str)
{
	if (!*str || *str == '\'')
		return (str);
	else if (*str == '$')
		return (ft_strdup(ft_getenv(str + 1)));
	else if (*str != '\"' || contains_var(str))
		return (str);
	return (parse_quoted_str(str));
}
