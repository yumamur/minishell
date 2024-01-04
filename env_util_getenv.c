/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util_getenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:59:39 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/04 16:20:17 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_core.h"
#include "typeft.h"
#include "libft/libft.h"

static t_c_char	inline	*ft_getenv_inline(t_c_char *name)
{
	char *const	*ptenv;
	size_t		len;
	t_ushort	name_start;
	t_ushort	ptenv_start;

	name_start = (name[0] * 256) + name[1];
	len = ft_strlen(name);
	ptenv = *g_env();
	while (*ptenv)
	{
		ptenv_start = ((*ptenv)[0] * 256) + (*ptenv)[1];
		if (ptenv_start == name_start && (*ptenv)[len] == '='
			&& !ft_strncmp(*ptenv + 2, name + 2, len - 2))
			return (&(*ptenv)[len + 1]);
		ptenv++;
	}
	return (NULL);
}

t_c_char	*ft_getenv(t_c_char *name)
{
	char *const	*ptenv;
	t_ushort	name_start;
	t_ushort	ptenv_start;

	if (!*g_env() || !(*g_env())[0] || !name || name[0] == '\0')
		return (NULL);
	if (name[1] == '\0')
	{
		ptenv = *g_env();
		((t_uchar *)&name_start)[0] = *(t_uchar *)name;
		((t_uchar *)&name_start)[1] = '=';
		while (*ptenv)
		{
			ptenv_start = *((t_ushort *)*ptenv);
			if (ptenv_start == name_start)
				return (&(*ptenv)[2]);
			ptenv++;
		}
	}
	else
		return (ft_getenv_inline(name));
	return (NULL);
}

char	*ft_getenv2(t_c_char *name)
{
	char	*ptr;
	char	*chr;
	int		l_name;
	int		l_var;

	ptr = **g_env();
	l_name = ft_strlen(name);
	while (ptr)
	{
		chr = ft_strchr(ptr, '=');
		if (chr)
			l_var = chr - ptr;
		else
			l_var = ft_strlen(ptr);
		if (l_name == l_var && !ft_strncmp(name, ptr, l_name))
			break ;
		++ptr;
	}
	return (ptr);
}