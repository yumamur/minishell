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

#include "error.h"
#include "libft/libft.h"
#include "typeft.h"
#include "lpc.h"

size_t	calculate_length(char *str);

t_bool	contains_variable(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			str = ft_strchr(str, '\'');
		else if (*str == '$')
			return (TRUE);
	}
	return (FALSE);
}

void	enxtend_string(char *str, char *result)
{
	size_t	len;

	while (*str)
	{
		if (*str == '\'')
		{
			len = ft_strchr(str, '\'') - str;
			ft_memcpy(result, str, len);
			str += len;
			result += len;
		}
		else if (*str != '$' || !*(str + 1))
			*result++ = *str++;
		else if (*(str + 1) == '?')
			
	}
}

char	*env_variable_extension(char *str)
{
	char	*result;

	if (contains_variable(str) == FALSE)
		return (str);
	result = malloc(calculate_length(str) + 1);
	if (!result)
	{
		error_handler("memory error", 1);
		return (str);
	}
	lpc_export(result, NULL);
	enxtend_string(str, result);
	return (result);
}
