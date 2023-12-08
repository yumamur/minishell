#include "typeft.h"
#include "libft/libft.h"

t_c_char	*ft_getenv(t_c_char *name);
char	*ft_strsubdup(const char *s, size_t start, size_t end);

char    *exchanger(char *arg, int q_flag)
{
    char    *tmp;
	char	*ret;
    int     i;
	int		j;

    i = 0;
	ret = NULL;
    while (arg[i] != '$')
	{
        ++i;
	}
	j = i;
	while (arg[j] && arg[j] != ' ')
		j++;
    tmp = ft_strsubdup(arg, i + 1, j);
    if (ft_getenv(tmp) && q_flag == 1)
	{
    	tmp = (char *)ft_getenv(tmp);
		ret = ft_strsubdup(arg, 0, i);
		ret = ft_strjoin(ret, tmp);
		tmp = ft_strsubdup(arg, j, ft_strlen(arg));
		ret = ft_strjoin(ret, tmp);
	}
	if (ft_getenv(tmp) && q_flag == 0)
		ret = ft_strdup(ft_getenv(tmp));
    return (ret);
}

char    **dollar_check(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strchr(arg[i], '$'))
		{
			if (arg[i][0] == '"')
            	arg[i] = exchanger(arg[i], 1);
			else
			 	arg[i] = exchanger(arg[i], 0);;
		}
        i++;
    }
    return (arg);
}


#include "env_util.h"
#include "builtin.h"
#include <stdio.h>
int main()
{
    char    *arg[4];
    char    *env[5];

    arg[0] = ft_strdup("taha");
    arg[1] = ft_strdup("$abc");
    arg[2] = ft_strdup("\"taha $abc  tatata\"");
    arg[3] = NULL;

    env[0] = ft_strdup("VAR1=ABC");
    env[1] = ft_strdup("VAR2");
    env[2] = ft_strdup("VAR3=taha");
    env[3] = ft_strdup("abc=1234");
    env[4] = NULL;

    env_init(env);
    ft_env();
    printf("-----------------\n");
    dollar_check(arg);
    int i = 0;
    while (arg[i])
    {
        printf("%s\n", arg[i]);
        i++;
    }
}
