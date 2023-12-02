#include "typeft.h"
#include "libft/libft.h"

void		ft_free_2pt(char **arr);
void		ft_free_change(void **dest, void *src);
char		*ft_file_name(char *path);
char		*ft_strjoin_frees1(char *s1, t_c_char *s2);
char		**ft_str_wordtab(char *line);
t_c_char	*ft_getenv(t_c_char *envp[], t_c_char *name);


void	add_cmd(char *allpaths[], char *cmd)
{
	while (*allpaths)
	{
		*allpaths = ft_strjoin_frees1(*allpaths, "/");
		*allpaths = ft_strjoin_frees1(*allpaths, (t_c_char *)cmd);
		allpaths++;
	}
}

t_c_char	*get_path(char *cmd, char *envp[])
{
	char	**allpaths;
	char	*ret;
	int		i;

	allpaths = ft_split(ft_getenv((t_c_char **)envp, "PATH"), ':');
	i = 0;
	add_cmd(allpaths, cmd);
	while (allpaths[i])
	{
		if (!access((t_c_char *)(allpaths[i]), F_OK))
		{
			ret = ft_strdup(allpaths[i]);
			ft_free_2pt(allpaths);
			return ((t_c_char *)ret);
		}
		i++;
	}
	ft_free_2pt(allpaths);
	return (NULL);
}

int	exec(char *cmd, char *envp[])
{
	char		**argcmd;
	t_c_char	*path;

	argcmd = ft_str_wordtab(cmd);
	if (!argcmd)
		return (-1);
	path = NULL;
	if (!access(argcmd[0], X_OK))
	{
		path = ft_strdup(argcmd[0]);
		ft_free_change((void **)&argcmd[0], ft_file_name((argcmd[0])));
		if (execve(path, argcmd, envp) == -1)
			write(2, argcmd[0], ft_strlen(argcmd[0]));
	}
	else
	{
		path = get_path(argcmd[0], envp);
		if (execve(path, argcmd, envp) == -1)
			write(2, argcmd[0], ft_strlen(argcmd[0]));
	}
	ft_free_2pt(argcmd);
	if (path)
		free((void *)path);
	exit(-1);
}
