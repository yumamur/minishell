/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_wordtab_util2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:27:41 by muhcelik          #+#    #+#             */
/*   Updated: 2023/12/28 15:28:34 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	one_quote_control(char *str, int i)
{
	(i)++;
	while (str[i] && str[i] != '\'')
	{
		(i)++;
		if (str[i] == '\t')
			str[i] = -2;
		else if (str[i] == ' ')
			str[i] = -3;
	}
	if (str[i] == '\'' && (i)++)
		return (1);
	else
		return (0);
}

int	two_quote_control(char *str, int i)
{
	(i)++;
	while (str[i] && str[i] != '"')
	{
		(i)++;
		if (str[i] == '\t')
			str[i] = -2;
		else if (str[i] == ' ')
			str[i] = -3;
	}
	if (str[i] == '"' && (i)++)
		return (1);
	else
		return (0);
}

int	quote_control(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (one_quote_control(str, i));
		else if (str[i] == '"')
			return (two_quote_control(str, i));
		break ;
	}
	return (0);
}