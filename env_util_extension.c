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

int	contains_var(char *str)
{
	if (*str == '$')
		return (1);
	else if (*str != '\"')
		return (0);
	while (*str)
	{
		if (*str == '$')
			return (1);
		++str;
	}
	return (0);
}

char	*env_var_extension(char *str)
{
	char	(*arr)[3];

	if (*str == '\'' || !contains_var(str))
		return (str);
	if (*str == '$')
		replace_str(str, );
}
