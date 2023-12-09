#include "libft/libft.h"
#include "env_util.h"
#include "pt_util.h"
#include "error.h"

int	export_repeat_check(char *str)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = ft_strdup(str);
	while (str[i] != '=')
		i++;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	if (ft_getenv(str))
	{
		env_remove(str);
		env_add(tmp);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int export_isvalid(char *str)
{
	int i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (errorer("export", str, "not a valid identifier", EXIT_FAILURE));
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			return (errorer("export", str, "not a valid identifier", EXIT_FAILURE));
	}
	return(1);
}

void	just_export(void)
{
	int	    i;
    char    **env;

    env = (char **)*g_env();
	i = 0;
	while(env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
}

int ft_export(char **arg)
{
	int	i;

	i = 0;
	if (!*g_env())
		return(errorer("export", "environment table does not exist", NULL, EXIT_FAILURE));
	if (!arg)
		just_export();
	else
	{
		while (i < arr_size((void **)arg))
		{
			if (export_isvalid(arg[i]))
			{
					if (!export_repeat_check(arg[i]))
						env_add(arg[i]);
			}
			else
			{
				ft_putstr_fd("export: not a valid identifier", 2);
				ft_putstr_fd(arg[i], 2);
			}
			i++;
		}
	}
	return (0);
}
