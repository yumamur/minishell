#include <unistd.h>
#include "typeft.h"
#include "builtin.h"
#define PATH_MAX 1024

t_c_char	*ft_getenv(t_c_char *envp[], t_c_char *name);
int	errorer(char *command, char *detail, char *error_message, int error_nb);

int	chg_dir(char **env, char *path)
{
	int	ctrl;
	char	*ret;
	char	*pwd[PATH_MAX];//char *[] ?
	char	*oldpwd;

	oldpwd = getcwd(pwd, PATH_MAX);
	ctrl = chdir(path);
	if (ctrl != 0)
		return(errorer("cd", path, "change directory failure", EXIT_FAILURE));
	ret = getcwd(pwd, PATH_MAX);
	if (!ret)
	{
        return (errorer("cd", path, "getcwd : error retrieving current directory", EXIT_FAILURE));
		ret = ft_strdup(path);
	}
	else
		ret = ft_strdup(pwd);
	set_env_val(env, ret, oldpwd);  //pwd yi değiştirme işlemi için

	//env_remove & env_add ***

	free(ret);
	return(0);
}

int	ft_cd(char **env, char **arg)
{
	char	*path;
	int		ctrl;

	ctrl = 0;
	if (!arg || !arg[1] || ft_isspace(arg[1][0])
		|| arg[1][0] == '\0' || ft_strncmp(arg[1], "--", 3) == 0)
	{
		path = ft_getenv(env, "HOME");
		if (!path || *path == '\0' || ft_isspace(*path))
			return(errorer("cd", 0, "HOME not set", EXIT_FAILURE));
		ctrl = chg_dir(env, path);
		if (ctrl != 0)
			return (1);
		return (0);
	}
	if (arg[2])
		return (errorer("cd", 0, "too many arguments", EXIT_FAILURE));
	if (ft_strncmp(arg[1], "-", 2) == 0)
	{
		path = ft_getenv(env, "OLDPWD");
		if (!path)
			return (errmsg_cmd("cd", 0, "OLDPWD not set", EXIT_FAILURE));
		ctrl = chg_dir(env, path);// bu fonksiyonu 'if' icine koy ctrl gereksiz
		if (ctrl != 0)
			return (1);
		return (0);
	}
	ctrl = chg_dir(env, path);
	if (ctrl != 0)
		return (1);
	return (0);
}
