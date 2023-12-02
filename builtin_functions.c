#include "libft/libft.h"
#include <errno.h>
#include <limits.h>
#define PATH_MAX_LENGTH 1024
void	ft_free_2pt(char **arr);

int	ret_for_exit = 0;

//------------HATA MESAJLARI------------

char	*join_args(char *arg, char *add)
{
	char	*tmp;

	if (!add)
		return (arg);
	if (!arg)
		return (ft_argdup(add));
	tmp = arg;
	arg = ft_argjoin(tmp, add);
	free_ptr(tmp);
	return (arg);
}

static int	add_detail_quotes(char *command)
{
	if (ft_argncmp(command, "export", 7) == 0
		|| ft_argncmp(command, "unset", 6) == 0)
		return (1);
	return (0);
}

int	errorer(char *command, char *detail, char *error_message, int error_nb)
{
	char	*msg;
	int		detail_quotes;

	detail_quotes = add_detail_quotes(command);
	msg = ft_argdup("minishell: ");
	if (command != 0)
	{
		msg = join_args(msg, command);
		msg = join_args(msg, ": ");
	}
	if (detail != 0)
	{
		if (detail_quotes)
			msg = join_args(msg, "`");
		msg = join_args(msg, detail);
		if (detail_quotes)
			msg = join_args(msg, "'");
		msg = join_args(msg, ": ");
	}
	msg = join_args(msg, error_message);
	ft_putendl_fd(msg, STDERR_FILENO);
	free(msg);
	return (error_nb);
}
//************************************************************//



//-------------------ENV ALMA/DEĞİŞTİRME----------//

char	*get_env_val(char **env, char *val)
{
	int	i;
	char	*tmp;

	i = 0;
	tmp = ft_argjoin(val, "=");
	while(env[i])
	{
		if (ft_argcmp(tmp, env[i]) == 0)
		{
			free(tmp);
			return(ft_argchr(env[i], "=") + 1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

void	set_env_val(char **env, char *pwd, char *oldpwd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (!ft_argncmp(env[i], "PWD=", 4))
		{
			tmp = ft_argjoin("PWD=", pwd);
			free(env[i]);
			env[i] = tmp;
		}
		else if (!ft_argncmp(env[i], "OLDPWD=", 7) && oldpwd)
		{
			tmp = ft_argjoin("OLDPWD=", oldpwd);
			free(env[i]);
			env[i] = tmp;
		}
		i++;
	}
}

//****************************************************************//



//--------------------CD İŞLEMLERİ------------------//

int	chg_dir(char **env, char *path)
{
	int	ctrl;
	char	*ret;
	char	*pwd[PATH_MAX_LENGTH];
	char	*oldpwd;

	oldpwd = getcwd(pwd, PATH_MAX_LENGTH);
	ctrl = chdir(path);
	if (ctrl != 0)
		return(errorer("cd", path, argerror(errno), errno));
	ret = getcwd(pwd, PATH_MAX_LENGTH);
	if (!ret)
	{
		return(errorer(("cd: error retrieving current directory", "getcwd", argerror(errno), errno)));
		ret = ft_argdup(path);
	}
	else
		ret = ft_argdup(pwd);
	set_env_val(env, ret, oldpwd);
	free(ret);
	return(0);
}

int	ft_cd(char **env, char **arg)
{
	char	*path;
	int		ctrl;

	ctrl = 0;
	if (!arg || !arg[1] || !arg[1][0] == '\0' || ft_argcmp(arg[1], " ") == 0 || ft_argcmp(arg[1], "--") == 0)
	{
		path = get_env_val(env, "HOME");
		if (!path || *path == '\0' || ft_argcmp(path, " ") == 0)
			return(errorer("cd", 0, "HOME not set", EXIT_FAILURE));
		ctrl = chg_dir(env, path);
		if (ctrl != 0)
			return (1);
		return (0);
	}
	if (arg[2])
		return (errorer("cd", 0, "too many arguments", EXIT_FAILURE));
	if (argcmp(arg[1], "-") == 0)
	{
		path = get_env_var_value(env, "OLDPWD");
		if (!path)
			return (errmsg_cmd("cd", 0, "OLDPWD not set", EXIT_FAILURE));
		ctrl = chg_dir(env, path);
		if (ctrl != 0)
			return (1);
		return (0);
	}
	ctrl = chg_dir(env, path);
	if (ctrl != 0)
		return (1);
	return (0);
}
//**************************************************************************//

//------------------------------PWD İŞLEMLERİ-------------------------------//

int	fd_pwd(char **env, char **arg)
{
	char	*pwd[PATH_MAX_LENGTH];

	if (arg[1])
		return (errorer("pwd", 0, "too many arguments", EXIT_FAILURE));
	if (getcwd(pwd, PATH_MAX_LENGTH) != 0)
		printf("%s\n", pwd);
	else
		return (errorer("pwd", 0, stderr(errno), errno));
	return (0);
}
//************************************************************************//


//------------------------------EXİT İŞLEMLERİ----------------------------//

int	ft_exit_atoi(char *arg)
{
	int			i;
	long		neg;
	long long	num;

	i = 0;
	neg = 1;
	num = 0;
	if ((arg[i] && (arg[i] == '-')) || (arg[i] == '+'))
		if (arg[i++] == '-')
			neg *= -1;
	while (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\t' || arg[i] == '\v'
		|| arg[i] == '\f' || arg[i] == '\r')
		i++;
	while (arg[i] >= 48 && arg[i] <= 57)
	{
		num = num * 10 + (arg[i] - 48);
		if (((i == 18 && neg == 1) && (arg[i] > '7' && arg[i] <= '9'))
			|| ((i == 19 && neg == -1) && (arg[i] == '9')))
			ret_for_exit = 2;
		i++;
	}
	return (num * neg);
}

void	exit_door(char *arg)
{
	long long	errnum;

	errnum = ft_exit_atoi(arg);
	if (!(errnum < LLONG_MAX && errnum > LLONG_MIN))
	{
		free(arg);
		exit(-1);
	}
	ret_for_exit = errnum % 256;
}

int	numeric_ctrl(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (errorer("eixt", "exit arguments must be numeric", stderr, 1));
		i++;
	}
	return (0);
}

int	ft_exit(char **arg)
{
	if (!arg[1])
	{
		ft_free_2pt(arg);
		exit(0);
	}
	if (numeric_ctrl(arg[1]) == 1)
	{
		ft_free_2pt(arg);
		exit(-1);
	}
	if (arg[2])
		return(errorer("exit", "too many argument for exit", stderr(errno), errno));
	else
		exit_door(arg[1]);
	exit(ret_for_exit);
}
//************************************************************************************//

//------------------------------ENV İŞLEMLERİ----------------------------------------//

int	ft_env(char *env)
{
	int	i;

	i = 0;
	if (!env)
		return(errorer("env", "dont have env.", stderr(errno), errno));
	while(env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return(0);
}
//***********************************************************************************//

//-----------------------------ECHO İŞLEMLERİ----------------------------------------//

int	arg_counter(char **arg)
{
	int	i;

	while (arg[i] != '\0')
		i++;
	return(i);
}

int	ft_echo(char **arg)
{
	int	n_flag;
	int	arg_size;
	int	i;

	n_flag = 0;
	i = 0;
	arg_size = arg_counter(arg);
	if (arg_size > 1)
	{
		if (ft_strcmp(arg[1], "-n") == 0)
		{
			n_flag == 1;
			i = 2;
		}
		while(arg[i])
		{
			ft_putstr_fd(arg[i], STDOUT_FILENO);
			if (arg[i + 1] && arg[i][0] != '\0')
				write (1, " ", 1);
			i++;
		}
	}
	if (n_flag == 0)
		write (1, "\n", 1);
	return (0);
}
//***********************************************************************************//

//-------------------------------UNSET İŞLEMLERİ-------------------------------------//

int	env_killer(char **env, char *arg)
{
	int	i;
	int freer;
	int	f_flag;
	char	**export; //struct yapılınca gelecek

	i = 0;
	freer = 0;
	f_flag = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], arg, ft_strlen(arg)) == 0)
		{
			f_flag = 1;
			while (env[i][freer])
			{
				env[i][freer] = 0;
				freer++;
			}
		}
		i++;
	}
	i = 0;
	freer = 0;
	while (export[i])
	{
		if (ft_strncmp(export[i], arg, ft_strlen(arg)) == 0)
		{
			f_flag = 1;
			while (export[i][freer])
			{
				export[i][freer] = 0;
				freer++;
			}
		}
		i++;
	}
	if (f_flag == 0)
		return(errorer("unset", "env cant found", stderr(errno), errno));
	return(0);

}

int	ft_unset(char **env, char *arg)
{
	int	i;

	i = 0;
	if (arg_counter(arg) > 1)
	{
		while (i <= arg_counter(arg))
		{
			env_killer(env, arg[i]);
			i++;
		}
	}
	else
		return (errorer("unset", "wrong argument count", stderrr(errno), errno));
	return(0);
}

//--------------------------------EXPORT İŞLEMLERİ------------------------------------//

char    **dynamic_malloc(char **path, char *new)
{
    int     count;
    char    **new_path;
    int     i;
    count = 0;
    while (path && path[count])
        count++;
    new_path = (char **)malloc(sizeof(char *) * (count + 2));
    if (!new_path)
        return (errorer("export", "malloc failure", stderr(errno), errno));
    i = -1;
    while (++i < count)
        new_path[i] = ft_strdup(path[i]);
    new_path[i] = ft_strdup(new);
    new_path[++i] = 0;
    i = -1;
    if (path)
    {
        while (path[++i])
            free(path[i]);
        free(path);
    }
    return (new_path);
}

int	env_borner(char **env, char *arg, int ex_flag)
{
	char *dec;

	dec = ft_strdup("declare -x ");
	if (!ft_isdigit(arg[0]))
	{
		if (ex_flag == 1)
		{
			dec = ft_strjoin(dec, arg);
			env = dynamic_malloc(env, dec);
			free(dec);
		}
		else
			env = dynamic_malloc(env, arg);
	}
	else
		return(errorer("export", "invalid export argument", stderr(errno), errno));
	return (0);
}

void ft_export(char **arg, char **env)
{
	int	i;
	char	**export;

	i = 0;
	export = env;
	if (arg_counter(arg) == 1 && ft_strcmp(arg[0], "export") == 0)
		ft_env(export);
	if (arg_counter(arg) > 1)
	{
		while (i <= arg_counter(arg))
		{
			if (ft_strchr(arg, '=') == 0)
				env_borner(export, arg[i], 1);
			else
				env_borner(env, arg[i], 0);
			i++;
		}
	}
	else
		return(errorer("export", "wrong argument count", stderr(errno), errno));
	return (0);
}

