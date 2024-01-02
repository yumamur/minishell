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
#include "msh_core.h"
#include "error.h"
#include "libft/libft.h"
#include "typeft.h"
#include "lpc.h"

size_t	calculate_length(char *str);
t_bool	contains_variable(char *str);

void	bypass_single_qt(char **src, char **dst)
{
	size_t	len;

	len = ft_strchr(*src, '\'') - *src;
	ft_memcpy(*dst, *src, len);
	*dst += len;
	*src += len;
}

void	copy_last_exit(char **src, char **dst)
{
	char	*buf;

	*src += 2;
	buf = ft_itoa(*_last_exit_location());
	if (!buf)
		return ;
	ft_memcpy(*dst, buf, ft_strlen(buf));
	*dst += ft_strlen(buf);
	free(buf);
}

void	copy_var_val(char **src, char **dst)
{
	char		*ptr;
	const char	*val;
	int			buf;

	ptr = *src;
	++ptr;
	while (*ptr && (ft_isalnum(*ptr) || *ptr == '_'))
		++ptr;
	buf = *ptr;
	*ptr = 0;
	val = ft_getenv(*src + 1);
	if (!val)
	{
		*src += ft_strlen(*src);
		*ptr = buf;
		return ;
	}
	ft_memcpy(*dst, val, ft_strlen(val));
	*ptr = buf;
	*src = ptr;
	*dst += ft_strlen(val);
}

void	enxtend_string(char *str, char *result)
{
	while (*str)
	{
		if (*str == '\'')
			bypass_single_qt(&str, &result);
		else if (*str != '$' || !*(str + 1))
			*result++ = *str++;
		else if (*(str + 1) == '?')
			copy_last_exit(&str, &result);
		else if (!ft_isalpha(*(str + 1)) && *(str + 1) != '_')
		{
			*result++ = *str++;
			*result++ = *str++;
		}
		else
			copy_var_val(&str, &result);
	}
}

char	*env_variable_extension(char *str)
{
	char	*result;

	if (contains_variable(str) == FALSE)
		return (str);
	result = ft_calloc(calculate_length(str) + 1, 1);
	if (!result)
	{
		error_handler("memory error", 1);
		return (str);
	}
	lpc_export(result, NULL);
	enxtend_string(str, result);
	return (result);
}
