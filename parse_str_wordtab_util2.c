/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_wordtab_util2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:03:28 by muhcelik          #+#    #+#             */
/*   Updated: 2024/01/06 04:03:29 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	str_update_util2(const char *str, int *i, char *new_str, int *j)
{
	if (*i && str[*i - 1] != ' ')
		new_str[(*j)++] = ' ';
	new_str[(*j)++] = str[(*i)++];
	new_str[(*j)++] = str[(*i)++];
	if (str[*i] != ' ' && str[*i] != '\0')
		new_str[(*j)++] = ' ';
}
