#include "typeft.h"
#include "libft/libft.h"
#include "env_util.h"
#include <stdlib.h>
#include <stdio.h>

char    *ft_space(char *s)
{
	int a = ft_strlen(s);
	char *sa = malloc(a + 1);
	int i = -1;
	while (++i < a)
		sa[i] = ' ';
	sa[i] = '\0';
	return(sa);
}

char    *exchanger(char *arg)
{
	int     tmp;
	int     tmp_start;
	const char  *dollar_value;
	int     i;
	char    *result;
	char    *result2 = ft_strdup("");
	i = 0;
	tmp_start = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			tmp = ++i;
			while (arg[i] && arg[i] != '$' && arg[i] != ' ' && arg[i] != '\"')
				++i;
			dollar_value = ft_getenv(ft_substr(arg, tmp, i - tmp ));
			if (!dollar_value)
				dollar_value = ft_space(ft_substr(arg, tmp-1, i - tmp));
			result = ft_strjoin(ft_substr(arg, tmp_start, tmp - tmp_start -1), dollar_value);
			result2 = ft_strjoin(result2, result);
			tmp_start = i;
			if (!ft_strchr(arg+i, '$'))
				result2 = ft_strjoin(result2, ft_substr(arg, i, ft_strlen(arg)));
		}
		i++;
	}
	return (result2);
}


char    **dollar_check(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == '\'')
			i++;
		else if (ft_strchr(arg[i], '$'))
		 	arg[i] = exchanger(arg[i]);
		i++;
	}
	return (arg);
}

// #include "env_util.h"
// #include "builtin.h"
// #include <stdio.h>
// char	**ft_str_wordtab(char *str);
// int main()
// {
// 	char    *arg[4];
// 	char    *env[5];
// 	char    **ret;

// 	arg[0] = ft_strdup("taha $abc \"duqcheck $abc a\" \'oneqcheck $abc b\' $abc \"taha $abc  tatata\" $abc \"taha$abc taha\"$abc,; $afc");
// 	//arg[1] = ft_strdup("$abc \"taha$abc taha\"$abc,; \'$afc");
// 	//arg[2] = ft_strdup("\"taha $abc  tatata\"");
// 	//arg[3] = NULL;

// 	env[0] = ft_strdup("VAR1=ABC");
// 	env[1] = ft_strdup("VAR2");
// 	env[2] = ft_strdup("VAR3=taha");
// 	env[3] = ft_strdup("abc=1234");
// 	env[4] = NULL;

// 	env_init(env);
// 	ft_env();
// 	printf("-----------------\n");
// 	ret = ft_str_wordtab(arg[0]);
// 	dollar_check(ret);
// 	int i = 0;
// 	while (ret[i])
// 	{
// 		printf("(%s)\n", ret[i]);
// 		i++;
// 	}
// }
