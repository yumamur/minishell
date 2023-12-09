#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "libft/libft.h"

char	*ft_strsubdup(const char *s, size_t start, size_t end)
{
	char	*dups;
	size_t	len;
	size_t	i;

	if (!s || start > end)
		return (NULL);
	len = ft_strlen(s);
	if (end > len)
		end = len; 
	len = end - start; 
	dups = ft_calloc(len + 1, 1);
	if (!dups)
		return (NULL);
	i = 0;
	while (start < end)
		dups[i++] = s[start++];
	dups[i] = '\0'; 
	return (dups);
}

int	parse_jump(t_c_char *cmd, int s_flag)
{
	int	i;
	
	i = 0;
	if (s_flag == 2)
		while ((cmd[i] && cmd[i + 1] && cmd[i + 2]) && ((cmd[i + 1] != '|') && (cmd[i + 1] != '<') 
			&& (cmd[i + 1] != '>') && (cmd[i + 1] != '&' && cmd[i + 2] != '&') && (cmd[i + 1] != '|' && cmd[i + 2] != '|') 
			&& (cmd[i + 1] != '>' && cmd[i + 2] != '>') && (cmd[i + 1] != '<' && cmd[i + 2] != '<')))
				i++;
	else if (s_flag == 1)
			while ((cmd[i] && cmd[i + 1]) && ((cmd[i + 1] != '|') && (cmd[i + 1] != '<') 
			&& (cmd[i + 1] != '>')))
				i++;
	i += s_flag;
	return (i);
}

t_c_char **parse_cmd(t_c_char *cmd, int a, t_c_char **arg)
{
	int	i;
	int	j;
	int	s_flag;
	int	ca_flag;

	j = 0;
	ca_flag = 0;
	printf("%c\n", cmd[0]);
	if (cmd[0] == '|' || cmd[0] == '<' || cmd[0] == '>' || cmd[0] == '&')
		return NULL;
	perror("elma");
	s_flag = is_seperator(cmd);
	i = parse_jump(cmd, s_flag);
	arg[a] = ft_strsubdup(cmd, j, i);
	a++;
	cmd = ft_strsubdup(cmd, i, ft_strlen(cmd));
	i = 0;
	if (s_flag == 1 && is_seperator_in(&cmd[i]))
	{
		arg[a] = ft_strsubdup(cmd, i, (i + s_flag));
		a++;
		ca_flag = 1;
	}
	else if (s_flag == 2 && is_double_seperator_in(&cmd[i]))
	{
		arg[a] = ft_strsubdup(cmd, i, (i + s_flag));
		a++;
		ca_flag = 1;
	}
	else
		arg[a] = ft_strsubdup(cmd, i, ft_strlen(cmd));

	if (ca_flag == 1 && cmd)
		cmd = ft_strsubdup(cmd, (i + s_flag), ft_strlen(cmd));
	if (cmd && is_seperator(cmd) != 0)
		parse_cmd(cmd, a, arg);
	else// if (ft_strchr(cmd, ' '))
		arg[a]= ft_strsubdup(cmd, i, ft_strlen(cmd));
	return(arg);
}
